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
  RegionAttribute Region::parseRegionAttribute(const string& attribute) {
    string attr;
    std::transform(attribute.begin(), attribute.end(), attr.begin(), ::tolower);
      if(attr == "cavern") {
        return RegionAttribute.CAVERN;
      }else if(attr == "magic") {
        return RegionAttribute.MAGIC;
      }else if(attr == "mine") {
        return RegionAttribute.MINE;
      }else if(attr == "default") {
        return RegionAttribute.DEFAULT;
      }else{
        throw std::invalid_argument("Unknown region attribute string '" + attribute + "'");
      }
    };
  };

  RegionType Region::parseRegionType(const string& type) {
    string t;
    std::transform(type.begin(), type.end(), t.begin(), ::tolower);
      if(t == "farmland") {
        return RegionType.FARMLAND;
      }else if(t == "forest") {
        return RegionType.FOREST;
      }else if(t == "hill") {
        return RegionType.HILL;
      }else if(t == "lake") {
        return RegionType.LAKE;
      }else if(t == "mountain") {
        return RegionType.MOUNTAIN;
      }else if(t == "sea") {
        return RegionType.SEA;
      }else if(t == "swamp") {
        return RegionType.SWAMP;
      }else{
        throw std::invalid_argument("Unknown region type string '" + type + "'");
      }
    };
  };

  Region::Region(json j) {
    m_key = j["key"];
    m_attribute = Region::parseRegionAttribute(j["attribute"]);
    m_type = Region::parseRegionType(j["type"]);
    m_lostTribe = j["lostTribe"];
    m_border = j["border"];
    m_center = std::make_tuple<int, int>(j["center"]["x"], j["center"]["y"]);
  };

  string Region::getKey(){ return m_key; };

  RegionAttribute Region::getAttribute(){ return m_attribute; };

  RegionType Region::getType(){ return m_type; };

  bool Region::hostsALostTribe(){ return m_lostTribe; };

};
