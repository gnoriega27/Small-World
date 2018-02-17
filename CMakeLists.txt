# CMake Build File
# Inspired from
# * https://rix0r.nl/blog/2015/08/13/cmake-guide/
# * http://foonathan.net/blog/2016/07/07/cmake-dependency-handling.html

cmake_minimum_required(VERSION 3.5.1)
project (smallworld VERSION 0.1 LANGUAGES CXX)

######################################
# Coverage Flags
######################################

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/externals)

# Code Coverage – We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" OFF)

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'include/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/main.cpp include/lib.hpp)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

######################################
# Vendor Dependencies
######################################

# Google Test Library
execute_process(COMMAND git submodule update --init -- vendor/googletest
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(vendor/googletest)

# @nlohmann's JSON Library
execute_process(COMMAND git submodule update --init -- vendor/json
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(vendor/json)

# @arximboldi's Immutable C++ data structures
execute_process(COMMAND git submodule update --init -- vendor/immer
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(vendor/immer)

# @Dobiasd's Functional Programming Library
execute_process(COMMAND git submodule update --init -- vendor/FunctionalPlus
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(vendor/FunctionalPlus)


######################################
# App
######################################

add_subdirectory(app)
add_subdirectory(test)
