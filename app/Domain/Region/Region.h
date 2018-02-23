//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_REGION_H
#define SMALLWORLD_REGION_H

#include <string>
#include <utility>
#include <nlohmann/json.hpp>
#include "RegionAttribute.h"
#include "RegionType.h"

using string = std::string;
using json = nlohmann::json;

namespace SmallWorld{
  class Region {
  public:
    Region(json j);
    string getKey() const { return m_key; };
    SmallWorld::RegionAttribute getAttribute() const { return m_attribute; };
    SmallWorld::RegionType getType() const { return m_type; };
    bool hostsALostTribe() const { return m_lostTribe; };
    string getOccupyingRaceID() const { return m_occupiedBy; };
  private:
    string m_key;
    SmallWorld::RegionAttribute m_attribute;
    SmallWorld::RegionType m_type;
    bool m_lostTribe;
    bool m_border;
    string m_occupiedBy;
    std::pair<int, int> m_center;
    static RegionAttribute parseRegionAttribute(const string& attribute);
    static RegionType parseRegionType(const string& type);
  };
};

#endif // SMALLWORLD_REGION_H
