# Project <proj> main cmake file

cmake_minimum_required(VERSION 3.3)

project(pikaxe VERSION 0.0.1)

# Option to install targets to env location
if(DEFINED ENV{PIKAXE_HOME})
     message("-- Will install PIKAXE binaries and libraries to location: " $ENV{PIKAXE_HOME})
	 set(CMAKE_INSTALL_PREFIX $ENV{PIKAXE_HOME})
else(DEFINED ENV{PIKAXE_HOME})
     message("-- Will install PIKAXE binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{PIKAXE_HOME})


# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Checks for headers not introduced in c89
include(cmake/header_check.cmake)

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)
