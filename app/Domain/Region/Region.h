//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_REGION_H
#define SMALLWORLD_REGION_H

#include <string>
#include <tuple>
#include <nlohmann/json.hpp>
#include "RegionAttribute.h"
#include "RegionType.h"

using string = std::string;
using json = nlohmann::json;

namespace SmallWorld{
  class Region {
  public:
    Region(json j);
    string getKey();
    RegionAttribute getAttribute();
    RegionType getType();
    bool hostsALostTribe();
  private:
    const string m_key;
    const RegionAttribute m_attribute;
    const RegionType m_type;
    const bool m_lostTribe;
    const bool m_border;
    const std::tuple<int, int> m_center;
    static RegionAttribute parseRegionAttribute(const string& attribute);
    static RegionType parseRegionType(const string& type);
  };
};

#endif // SMALLWORLD_REGION_H
