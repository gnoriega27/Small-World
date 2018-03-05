//
// Created by Philippe Hebert on 2018-02-16.
//
#include <string>
#include <tuple>
#include <nlohmann/json.hpp>
#include "RegionAttribute.h"
#include "RegionType.h"
#include "Region.h"

using string = std::string;
using json = nlohmann::json;

namespace SmallWorld {
  SmallWorld::RegionAttribute SmallWorld::Region::parseRegionAttribute(const string& attribute) {
    string attr;
    std::transform(attribute.begin(), attribute.end(), attr.begin(), ::tolower);
    if(attr == "cavern") {
      return SmallWorld::RegionAttribute::CAVERN;
    }else if(attr == "magic") {
      return SmallWorld::RegionAttribute::MAGIC;
    }else if(attr == "mine") {
      return SmallWorld::RegionAttribute::MINE;
    }else if(attr == "default") {
      return SmallWorld::RegionAttribute::DEFAULT;
    }else{
      throw std::invalid_argument("Unknown region attribute string '" + attribute + "'");
    }
  }

  SmallWorld::RegionType SmallWorld::Region::parseRegionType(const string& type) {
    string t;
    std::transform(type.begin(), type.end(), t.begin(), ::tolower);
    if(t == "farmland") {
      return SmallWorld::RegionType::FARMLAND;
    }else if(t == "forest") {
      return SmallWorld::RegionType::FOREST;
    }else if(t == "hill") {
      return SmallWorld::RegionType::HILL;
    }else if(t == "lake") {
      return SmallWorld::RegionType::LAKE;
    }else if(t == "mountain") {
      return SmallWorld::RegionType::MOUNTAIN;
    }else if(t == "sea") {
      return SmallWorld::RegionType::SEA;
    }else if(t == "swamp") {
      return SmallWorld::RegionType::SWAMP;
    }else{
      throw std::invalid_argument("Unknown region type string '" + type + "'");
    }
  }

  SmallWorld::Region::Region(json j) {
    m_key = j["key"].get<string>();
    m_attribute = Region::parseRegionAttribute(j["attribute"].get<string>());
    m_type = Region::parseRegionType(j["type"].get<string>());
    m_lostTribe = j["lostTribe"].get<bool>();
    m_border = j["border"].get<bool>();
    m_center = std::make_pair<int, int>(j["center"]["x"].get<int>(), j["center"]["y"].get<int>());
    m_occupiedBy = "";
  }

}
