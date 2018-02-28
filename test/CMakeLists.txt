set(GTEST_SHUFFLE 1)

add_executable(
  Small-World-Test
    main.cpp
    test.cpp
    integration/Map/map.test.cpp
)

target_include_directories(Small-World-Test PUBLIC ../vendor/googletest/googletest/include
        ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Small-World-Test PUBLIC gtest)
