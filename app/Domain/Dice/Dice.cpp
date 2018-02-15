//
// Created by Gabriel Noriega on 2018-02-14.
//

#include <random>
#include "Dice.h"
#include <iomanip>

using std::cout;
using std::endl;


int Dice::generateRandomNumber() {
    const int range_from = 0;
    const int range_to = 6;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);
    return distr(generator);
}

int Dice::transformRoll(int value) const {
    (value < 3) ? (value = 0) : (value -= 3);
    return value;
}

int Dice::roll() {
    int value = transformRoll(generateRandomNumber());
    m_rollTracker.at(value)++;
    m_totalRolls++;

    return value;
}

void Dice::displayStats() const {
    cout << "Statistics" << "\n------------------------------------" << endl;
    cout << "Number  |  Times Rolled  | Percentage " << endl;

    int i = 0;
    for (auto const &value: m_rollTracker) {
        cout << "  " << i << "     |       " << value << "        |   ";
        cout << std::fixed << std::setprecision(2);

        if (m_totalRolls > 0) {
            cout << (float) value / (m_totalRolls) * 100 << endl;
        } else {
            cout << 0.00 << endl;
        }
        i++;
    }


}
