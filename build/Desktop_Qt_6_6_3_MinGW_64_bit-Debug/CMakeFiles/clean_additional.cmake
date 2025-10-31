# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\hospital-dashboard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hospital-dashboard_autogen.dir\\ParseCache.txt"
  "hospital-dashboard_autogen"
  )
endif()
