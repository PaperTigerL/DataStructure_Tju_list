# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-src"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-build"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/tmp"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src"
  "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/file/datastruct/cmake-build-debug/_deps/ejson4cpp-subbuild/ejson4cpp-populate-prefix/src/ejson4cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
