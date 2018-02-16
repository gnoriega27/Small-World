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

    const int range_from = 0;

    const int range_to = 6;

    // Holds the times a face has been rolled (0 = blank, 1, 2, 3)
    std::vector<int> m_rollTracker;

    // Generate random number between 1 - 6
    int generateRandomNumber();

    // Transform value into 0 - 3 range
    int transformRoll(int value) const;

public:
    Dice() : m_rollTracker(4, 0) {}

    ~Dice() = default;

    // roll the die and return its value
    int roll();

    // returns total times the die has been rolled
    int getTotalRolls() { return m_totalRolls; }

    // return a vector with the times each number has been rolled
    std::vector<int> getTotalRollsContainer() const {
        std::vector<int> copyVector(m_rollTracker);
        return copyVector;
    };

    // display the statistics in a formatted way.
    void displayStats() const;

};


#endif //SMALLWORLD_DICE_H
