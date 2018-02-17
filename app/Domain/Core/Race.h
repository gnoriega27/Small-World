//
// Created by Gabriel Noriega on 2018-02-16.
//

#ifndef SMALLWORLD_RACE_H
#define SMALLWORLD_RACE_H

#include <iostream>
#include "../Ability/IAbility.h"
#include "../Inventory/Inventory.h"

template<typename T>
class Race {
private:
    IAbility const m_defaultAbility;
    std::string const m_id;
    bool const m_isInDecline;
    IAbility const m_raceAbility;
    IActiveAbility const m_activeAbility;
//    Waiting for region implemenetation
//    std::vector<Region> const m_regions;
    Inventory<T> const m_tokenInventory;

public:
    // default constructor
    Race(IAbility v_defaultAbility, const std::string v_id, bool v_isInDecline,
         IAbility v_raceAbility, IActiveAbility v_activeAbility, Inventory<T> v_tokenInventory)
            : m_defaultAbility(v_defaultAbility), m_id(v_id), m_isInDecline(v_isInDecline),
              m_raceAbility(v_raceAbility), m_activeAbility(v_activeAbility), m_tokenInventory(v_tokenInventory) {}


    // Copy Constructor
    Race(const Race &other) : m_defaultAbility(other.m_defaultAbility), m_id(other.m_id),
                              m_isInDecline(other.m_isInDecline),
                              m_raceAbility(other.m_raceAbility), m_activeAbility(other.m_activeAbility),
                              m_tokenInventory(other.m_tokenInventory) {}

//    std::vector<Region> getConqueredRegions();
//    void addConqueredRegion(Region region);
//    void removeConqueredRegion(Region region);

    bool isInDecline() { return m_isInDecline; }


    // Return a copy of this Race but change it to be in decline and delete old one.
    void enterDecline();

    // Testing purposes. For demo.
    void printRaceInfo();
};

template<typename T>
void Race<T>::printRaceInfo() {
    std::cout << "ID: " << m_id << "  Is in Decline: ";
    if (m_isInDecline) {
        std::cout << "True";
    } else {
        std::cout << "False";
    }
    std::cout << std::endl;
}

#endif //SMALLWORLD_RACE_H
