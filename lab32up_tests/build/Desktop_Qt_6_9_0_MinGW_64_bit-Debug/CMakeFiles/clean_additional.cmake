# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\lab32up_tests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lab32up_tests_autogen.dir\\ParseCache.txt"
  "lab32up_tests_autogen"
  )
endif()
