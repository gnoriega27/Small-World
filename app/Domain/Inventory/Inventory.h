//
// Created by Gabriel Noriega on 2018-02-16.
//

#ifndef SMALLWORLD_INVENTORY_H
#define SMALLWORLD_INVENTORY_H

#include <map>
#include <iostream>
#include <vector>

template<class T>
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
    customMapType getInventroy() const { return m_inventory; }

    void
    ~Inventory() {
        m_inventory.clear();
    };

};

#endif //SMALLWORLD_INVENTORY_H