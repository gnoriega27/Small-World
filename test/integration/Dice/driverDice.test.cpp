//
// Created by Gabriel Noriega on 2018-02-16.
//
#include "driverDice.test.h"
#include "../../../app/Domain/Dice/Dice.cpp"
#include <iostream>

using std::cout;
using std::endl;

void diceDriver() {
    cout << "Dice Driver started\n" << endl;
    auto *aDie = new Dice();

//    Test roll method.
    cout << "Testing rolling capabilities" << endl;
    int valueRolled = aDie->roll();
    cout << "\nValue rolled: " << valueRolled << endl;

//    More rolls
    aDie->roll();
    aDie->roll();
    aDie->roll();
    aDie->roll();
    aDie->roll();

//    Display stats in a formatted way.
    cout << endl;
    aDie->displayStats();
    cout << endl;

//    If a vector of the stats is desired, uncomment next line
//    aDie->getTotalRollsContainer();

    delete (aDie);
    cout << "\nDice Driver finished" << endl;

}
