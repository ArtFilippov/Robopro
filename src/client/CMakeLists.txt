cmake_minimum_required(VERSION 3.5)

project(Client)

set(CLIENT_SRC client_main.c client.c client.h)

add_executable(Client ${CLIENT_SRC})

include_directories(../common)

target_link_libraries(Client SendRecv)