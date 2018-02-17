//
// Created by Gabriel Noriega on 2018-02-16.
//

#ifndef SMALLWORLD_INVENTORY_H
#define SMALLWORLD_INVENTORY_H

#include <map>
#include <iostream>
#include <vector>

template<typename T>
class Inventory {
private:
    typedef std::map<std::string, std::vector<T>> customMapType;
    customMapType m_inventory;
    bool m_frozen{false};
public:
    Inventory(std::map<std::string, std::vector<T>> v_inventory, bool v_frozen)
            : m_inventory(v_inventory), m_frozen(v_frozen) {}

    // Return copy of the inventory;
    customMapType getInventoryCopy() const;

    // Returns the inventory - able to modify
    customMapType getInventory() const { return m_inventory; }

    ~Inventory() {
        m_inventory.clear();
    };

};

template<typename T>
typename Inventory<T>::customMapType Inventory<T>::getInventoryCopy() const {
    return Inventory<T>::customMapType();
}

#endif //SMALLWORLD_INVENTORY_H