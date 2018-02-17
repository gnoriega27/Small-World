//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_REGION_ATTRIBUTE_H
#define SMALLWORLD_REGION_ATTRIBUTE_H

#include <stdexcept>
#include <algorithm>
#include <string>

using string = std::string;

namespace SmallWorld {
  enum class RegionAttribute {
    CAVERN,
    MAGIC,
    MINE,
    DEFAULT
  };
};

#endif // SMALLWORLD_REGION_ATTRIBUTE_H
