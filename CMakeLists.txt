# CMake Build File
# Inspired from
# * https://rix0r.nl/blog/2015/08/13/cmake-guide/
# * http://foonathan.net/blog/2016/07/07/cmake-dependency-handling.html

cmake_minimum_required(VERSION 3.5.1)
project (smallworld VERSION 0.1 LANGUAGES CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
# include(GNUInstallDirs)

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

add_subdirectory(app)
execute_process(COMMAND git submodule update --init -- vendor/googletest
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(vendor/googletest)
add_subdirectory(test)
