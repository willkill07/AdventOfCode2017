add_library(AdventUtils
  io.cpp
  md5.cpp
  util.cpp)

target_compile_options(AdventUtils PUBLIC ${ADVENT_CXX_FLAGS})
target_link_libraries(AdventUtils ${ADVENT_LINK_FLAGS})
