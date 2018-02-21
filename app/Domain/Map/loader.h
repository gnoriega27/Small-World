//
// Created by Philippe Hebert on 2018-02-19.
//
#ifndef SMALLWORLD_MAP_LOADER_H
#define SMALLWORLD_MAP_LOADER_H

#include <memory>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../../Service/JSON/AJV.h"
#include "Graph.h"
#include "../Region/Region.h"
#include "../Region/RegionAttribute.h"
#include "../Region/RegionType.h"

using string = std::string;
using json = nlohmann::json;

namespace SmallWorld{
  namespace Map {
    using Region = SmallWorld::Region;
    using RegionAttribute = SmallWorld::RegionAttribute;
    using RegionType = SmallWorld::RegionType;
    using region_ptr = std::shared_ptr<Region>;

    namespace {
      json* readJSONFile(const string& path);

      json* readMap(const string& path, const string& schema);

      std::vector<std::pair<string, region_ptr>> extractRegions(const json& map);

      std::vector<std::pair<string, string>> extractEdges(const json& map);
    };

    std::shared_ptr<Map::Graph<Region>> loadMap(const string& path, const string& schema = "./map.ajv.json");
  };
};

#endif // SMALLWORLD_MAP_LOADER_H
