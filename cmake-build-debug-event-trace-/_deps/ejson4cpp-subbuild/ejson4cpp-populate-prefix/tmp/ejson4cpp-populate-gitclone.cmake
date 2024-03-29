# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitclone-lastrun.txt" AND EXISTS "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitinfo.txt" AND
  "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitclone-lastrun.txt" IS_NEWER_THAN "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "D:/software/git/Git/cmd/git.exe" 
            clone --no-checkout --depth 1 --no-single-branch --config "advice.detachedHead=false" "https://gitee.com/acking-you/ejson4cpp.git" "ejson4cpp-src"
    WORKING_DIRECTORY "D:/file/datastruct/cmake-build-debug-event-trace-/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://gitee.com/acking-you/ejson4cpp.git'")
endif()

execute_process(
  COMMAND "D:/software/git/Git/cmd/git.exe" 
          checkout "origin/master" --
  WORKING_DIRECTORY "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'origin/master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "D:/software/git/Git/cmd/git.exe" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitinfo.txt" "D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'D:/file/datastruct/cmake-build-debug-event-trace-/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/ejson4cpp-populate-gitclone-lastrun.txt'")
endif()
