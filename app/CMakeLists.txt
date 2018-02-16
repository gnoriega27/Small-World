add_executable(Small-World main.cpp Domain/Dice/Dice.cpp Domain/Dice/Dice.h Domain/Tokens/Token.h Domain/Tokens/TokenType.h Domain/Tokens/TokenSubtype.h Domain/Ability/IAbility.h Domain/Ability/AbilityType.h)
include_directories(
        ${CMAKE_SOURCE_DIR}/include
)
