//
// Created by Gabriel Noriega on 2018-02-16.
//

#include "Inventory.h"

Inventory::customMapType Inventory::getInventoryCopy() const {
    customMapType copyInventory = m_inventory;
    return copyInventory;
};
