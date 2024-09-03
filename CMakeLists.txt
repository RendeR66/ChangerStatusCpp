cmake_minimum_required(VERSION 3.10)
project(ChangerStatusCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(ChangerStatusCpp src/main.cpp)
target_link_libraries(ChangerStatusCpp discord-rpc)