cmake_minimum_required(VERSION 3.5)

project(InventorySystem LANGUAGES C)

#target_include_directories(InventorySystem PRIVATE ${CMAKE_SOURCE_DIR})

set(SOURCES variables.h ventana.h ControllerLogin.h main.c)

add_executable(InventorySystem ${SOURCES})

install(TARGETS InventorySystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
