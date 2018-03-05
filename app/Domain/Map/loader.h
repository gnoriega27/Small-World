//
// Created by Philippe Hebert on 2018-02-19.
//
#ifndef SMALLWORLD_MAP_LOADER_H
#define SMALLWORLD_MAP_LOADER_H

#include <memory>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../../Services/JSON/AJV.h"
#include "Graph.cpp"
#include "../Region/Region.h"
#include "../Region/RegionAttribute.h"
#include "../Region/RegionType.h"

using std::string;
using nlohmann::json;

namespace SmallWorld{
  namespace Map {
    using SmallWorld::Region;

    std::shared_ptr<Map::Graph<Region>> loadMap(const string& map_path, const string& schema_path);
  }
}

#endif // SMALLWORLD_MAP_LOADER_H
