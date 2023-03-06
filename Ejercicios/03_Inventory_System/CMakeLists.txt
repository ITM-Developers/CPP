cmake_minimum_required(VERSION 3.5)

project(InventorySystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp)

add_executable(InventorySystem ${SOURCES})

install(TARGETS InventorySystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
