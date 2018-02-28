add_executable(
  Small-World
    main.cpp
    Domain/Dice/Dice.cpp
    Domain/Dice/Dice.h
    Domain/Tokens/Token.h
    Domain/Tokens/TokenType.h
    Domain/Tokens/TokenSubtype.h
    Domain/Region/Region.h
    Domain/Map/Graph.h
    Domain/Map/loader.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/vendor
)
