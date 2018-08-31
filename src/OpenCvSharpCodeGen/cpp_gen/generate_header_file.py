"""Exception safe C++ wrapper generator 

This module uses the c++ header files of opencvsharp to generate a new 
header which servers as a supplementary layer between the current c++ 
headers and the pinvoke boundary.     
Every call to the currently used functions are wrapped in a try-catch 
block. The return value of the generated functions indicates the 
occurence of an exception.
"""
import sys
import re
import os

from typing import Tuple, List

PADDING = 4
EXC_SAFE_FUNC_SUFFIX = "_excsafe"
#GEN_FILE_NAME = "exc_safe_generated.h"
FUNC_COUNT = 0

def main():
  externDir   = sys.argv[1]
  genFileName = sys.argv[2]
  targetDir = externDir
  # template for the generated file
  generatedFileHeader = """\
#ifndef _CPP_GENERATED_NATIVE_FUNC_H_
#define _CPP_GENERATED_NATIVE_FUNC_H_

// THIS CLASS IS GENERATED

#include "include_opencv.h"
"""
  generatedFileFooter = """#endif"""
  filePaths = getFilesPaths(externDir)
  # remove entry of file we want to write if it exists already
  if genFileName in filePaths:
    print("file {} already exists".format(genFileName))
    filePaths.remove(genFileName)
  generatedFileFunctionsTemplate = "{}\n"*len(filePaths)
  fileStrings = []
  for filePath in filePaths:
    with open(filePath, 'r') as file:
      fileString = str(file.read())
      fileStrings.append(getNewFileString(fileString))
  generatedFileString = "{}{}{}".format(generatedFileHeader, generatedFileFunctionsTemplate.format(*fileStrings), generatedFileFooter)
  with open(os.path.join(targetDir, genFileName), 'w') as file:
    file.write(generatedFileString) 
  print(FUNC_COUNT)

def getFilesPaths(rootDir: str) -> List[str]:
  """ Iterate over every  file recursively, return list of files """
  filepaths = [] 
  for subdir, dirs, files in os.walk(rootDir):
    for file in files:
      if file.endswith(".h"):
        filepaths.append(os.path.join(subdir, file))
  return filepaths


def getNewFileString(fileString: str) -> str:
  """ Given the content of a file, return the new functions as string"""
  def getNewFunctions(fileString: str) -> List[str]:
    """ Given the content of a file, return the new functions as list"""
    functions = getFunctions(fileString)
    return list(map(getNewFunctionString, functions))
  newFunctions = getNewFunctions(fileString)
  # update global variable to keep track of the number of functions found
  global FUNC_COUNT
  FUNC_COUNT += len(newFunctions) 

  newFileString = "{}\n" * len(newFunctions)
  return newFileString.format(*newFunctions)


def getFunctions(fileString: str) -> List[str]:
  """Extracts all the functions as substrings

  Given a string yielded from a C++ file, assuming nested functions/blocks 
  possible and that the line begins with the characters 'CVAPI'
  """
  def findComments(fileString: str) -> List[str]:
    comments = []
    index = 2
    while index < len(fileString):
      index += 1
      if fileString[(index-2):index] == "/*":
        begCom = index-2
        while index < len(fileString):
          if fileString[(index-2):index] == "*/":
            comments.append( fileString[begCom:index])
            break
          index += 1
    return comments 

  def removeComments(fileString, comments):
    for comment in comments:
      fileString = fileString.replace(comment, "")
    return fileString

  comments = findComments(fileString)
  fileString = removeComments(fileString, comments)

  # find all function that begin with "CVAPI"
  pattern = re.compile(r'^CVAPI.*?{.*?}', re.MULTILINE|re.DOTALL)
  # get every index of the occurences of CVAPI
  funBeg = list(re.finditer(pattern, fileString))
  # TODO: this could better be done by using recursive regex
  functionStrings = []
  for item in funBeg:
    beg, end = item.start(), item.end()
    currentString = fileString[beg:end]
    # Count occ of {
    cOpenBrac = currentString.count("{")
    cCloseBrac = currentString.count("}")
    while cOpenBrac > cCloseBrac:
      end += 1
      if fileString[end-1] == "}":
        cCloseBrac += 1
      elif fileString[end-1] == "{":
        cOpenBrac += 1
    functionString = fileString[beg:end]
    if not "CVAPI_EXC" in functionString: 
      functionStrings.append(functionString)
  return functionStrings


def getNewFunctionString(functionString: str) -> str:
  """Takes a function string and returns an altered function containing
  the call to the function wrapped in a try-catch block. 
  Account for non-void return type if necessary. 
  """

  signature, _, _ = splitFunctionString(functionString)
  returnType = getReturnType(signature)
  funcName = getName(signature) 
  parameterList = getParameterList(signature)

  def getParameterString(parameterList):
    # Add return value to parameterlist if necessary
    parameterString = ""
    if len(parameterList) > 1:
      parameterString = parameterList[0]
      for entry in parameterList[1:]:
        parameterString += ", {}".format(entry) 
    elif len(parameterList) == 1:
      parameterString = "{}".format(parameterList[0])
    return parameterString.strip()

  def getParameterName(parameterString):
    end = len(parameterString)
    while parameterString[end-1] == " " :
      end=end-1
    beg = end-1
    while( not  (parameterString[beg:beg+1] == " " or parameterString[beg:beg+1] == "*" or  parameterString[beg:beg+1] == "&" )  ):
      beg -= 1
    return parameterString[(beg+1):end]

  parameterString = getParameterString(list(map(getParameterName, parameterList)))
  retString = ""
  # Add a supplementary parameter which contains a ref to the return type
  if not returnType == "void":
    retString = "ret = "
    parameterList.insert(0, " {} &ret".format(returnType))
  newParameterString = getParameterString(parameterList)

  # body hast a try catch block and calls the appropriate function
  # Return values indicate if exception happened in opencv
  body = """try
    \t{{
    \t    {0}{1}({2});
    \t    return false;
    \t}}
    \tcatch(std::exception e)
    \t{{
    \t    return true;
    \t}}
    """.format(retString, funcName, parameterString)
  newFuncName = funcName + EXC_SAFE_FUNC_SUFFIX
  newFunctionString = "CVAPI(bool) {} ({}) {{\n {} }}".format(newFuncName, newParameterString, body)
  return newFunctionString


def getReturnType(signature: str) -> str:
  """Use regex to get the funciton return type"""
  typeStringMatch =  re.match(r'(CVAPI\()(.*?)(\))', signature)
  typeString = typeStringMatch.group(2)
  return typeString


def getName(signature: str) -> str:
  """Use regex to get the funciton name"""
  nameStringMatch =  re.match(r'(CVAPI\()(.*?)(\))(.*?)\(', signature)
  return  nameStringMatch.group(4)


def getParameterList(signature: str) -> List[str]:
  """Get the parameter list from signature string

  First find the last closing bracket and move backwards from it while 
  counting opening and closing brackets to account for nested brackets.
  """

  end = len(signature)-1
  while not signature[end] == ")":
    end -= 1;
  beg = end
  cOpenBrac = 0
  cCloseBrac = 1
  while not cOpenBrac == cCloseBrac:
    beg -= 1
    if signature[beg] == ")":
      cCloseBrac += 1
    elif signature[beg] == "(":
      cOpenBrac += 1
  parameterString = signature[beg+1:end].strip()
  if parameterString == "":
    return []
  else:
    return parameterString.split(",")


def splitFunctionString(funcString: str)->Tuple[str,str,str]:
  """Takes a function String and splits it into a prefix, its content and a suffix (})"""
  # first occurrence of "{"    
  prefixEndIndex = funcString.index("{")+1
  #iterate to the first occurence of a new char which is not space, tab or newline and newline has not been reached yet
  while funcString[prefixEndIndex] in " \t\n" and not funcString[prefixEndIndex-1] == "\n" :
    prefixEndIndex += 1
  # outermost "}" 
  suffixBeginIndex = funcString.rindex("}")
  #iterate backwards to the first occurence of a new char which is not space, tab or newline and newline has not been reached yet
  while funcString[suffixBeginIndex-1] in " \t\n" and not funcString[suffixBeginIndex] == "\n" :
    suffixBeginIndex -= 1

  prefix = funcString[:prefixEndIndex]
  innerBlock = funcString[prefixEndIndex:suffixBeginIndex]
  suffix = funcString[suffixBeginIndex:]
  return (prefix,innerBlock,suffix)

if __name__ == "__main__":
  main()
