add_executable(Advent
  Advent.cpp
  io.cpp
  util.cpp)

target_compile_options(Advent PUBLIC ${CXX_TARGET_FLAGS})
target_link_libraries(Advent Threads::Threads)

install(TARGETS Advent RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})
