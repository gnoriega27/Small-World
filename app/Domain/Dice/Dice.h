//
// Created by Gabriel Noriega on 2018-02-14.
//

#ifndef SMALLWORLD_DICE_H
#define SMALLWORLD_DICE_H

#include <iostream>
#include <vector>

class Dice {
private:
    int m_totalRolls{0};

    // Holds the times a face has been rolled (0 = blank, 1 ,2 ,3)
    std::vector<int> m_rollTracker;

    // Generate random number between 0 - 6
    int generateRandomNumber();

    // Transform value into 0 - 3 range
    int transformRoll(int value) const;

public:
    Dice() : m_rollTracker(4, 0) {}

    ~Dice() = default;;

    int roll();

    int getTotalRolls() const { return m_totalRolls; }

    void displayStats() const;

};


#endif //SMALLWORLD_DICE_H
