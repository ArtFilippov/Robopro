cmake_minimum_required(VERSION 3.5)

project(Server)

set(SERVER_SRC server_main.c server.c server.h)


add_executable(Server ${SERVER_SRC})

include_directories(../common)
include_directories(../matrix)

target_link_libraries(Server Matrix SendRecv)

