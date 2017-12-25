add_library(AdventUtils
  io.cpp
  md5.cpp
  util.cpp)

target_compile_options(AdventUtils PUBLIC ${CXX_TARGET_FLAGS})
target_link_libraries(AdventUtils Threads::Threads)
