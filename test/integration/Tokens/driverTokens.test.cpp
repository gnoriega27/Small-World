//
// Created by Gabriel Noriega on 2018-02-16.
//
#include "driverTokens.test.h"
#include <iostream>

using std::cout;
using std::endl;

void tokenDriver() {
    cout << "Tokens Driver started\n" << endl;
    cout << "Creating one token of each type" << endl;
    Token *amazonsToken = new Token(TokenType::RACE, TokenSubtype::AMAZONS);
    Token *mountainToken = new Token(TokenType::TERRAIN, TokenSubtype::MOUNTAINS);
    Token *abilityToken = new Token(TokenType::ABILITY, TokenSubtype::HERO);
    cout << "Done! No errors" << endl;
    delete (amazonsToken);
    delete (mountainToken);
    delete (abilityToken);
    cout << "\nTokens Driver finished" << endl;

}

//  Token Types:
//  RACE, ABILITY, TERRAIN

// Token Subtypes:
//    AMAZONS,
//    DWARVES,
//    ELVES,
//    GHOULS,
//    GIANTS,
//    HALFLINGS,
//    HUMANS,
//    ORCS,
//    RATMEN,
//    SKELETONS,
//    SORCERERS,
//    TRITONS,
//    TROLLS,
//    WIZARDS,
//    LOSTTRIBE,
//    TROLLLAIR,
//    FORTESS,
//    ENCAMPMENT,
//    HOLEINTHEGROUND,
//    HERO,
//    DRAGON