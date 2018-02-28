//
// Created by Philippe Hebert on 2018-02-21.
//
#include "loader.h"

using std::string;
using nlohmann::json;

namespace SmallWorld{
  namespace Map {
    using SmallWorld::Region;
    using SmallWorld::RegionAttribute;
    using SmallWorld::RegionType;
    using region_ptr = std::shared_ptr<Region>;
    using SmallWorld::AJV;

    namespace {
      json* readJSONFile(const string& path) {
        std::ifstream i(path);
        json j;
        i >> j;
        return new json(j);
      };

      json* readMap(const string& map_path, const string& schema_path) {
        AJV ajv;
        json* schema = readJSONFile(schema_path);
        json* map = readJSONFile(map_path);
        if(ajv.validate(schema, map)){
          delete schema;
          return map;
        }else{
          delete schema;
          throw ajv.errors;
        }
      };

      std::vector<std::pair<string, region_ptr>> extractRegions(const json& map) {
        std::vector<std::pair<string, region_ptr>> regions;
        regions.reserve(map["nodes"].size());
        std::transform(
          map["nodes"].begin(),
          map["nodes"].end(),
          std::back_inserter(regions),
          [](const json& r) -> std::pair<string, region_ptr> {
            return std::make_pair<string, region_ptr>(r["key"], std::make_shared<Region>(r));
          }
        );
        return regions;
      };

      std::vector<std::pair<string, string>> extractEdges(const json& map) {
        std::vector<std::pair<string, string>> edges;
        edges.reserve(map["edges"].size());
        std::transform(
          map["edges"].begin(),
          map["edges"].end(),
          std::back_inserter(edges),
          [](const json& edge){ return std::make_pair<string, string>(edge["source"], edge["target"]); }
        );
        return edges;
      };
    };

    std::shared_ptr<Map::Graph<Region>> loadMap(const string& path, const string& schema = "./map.ajv.json") {
      using Graph = SmallWorld::Map::Graph<Region>;
      json* map = readMap(path, schema);
      std::vector<std::pair<string, region_ptr>> regions = extractRegions(*map);
      std::vector<std::pair<string, string>> edges = extractEdges(*map);
      std::shared_ptr<Graph> pgraph = std::make_shared<Graph>(regions, edges);
      delete map;
      return pgraph;
    };
  };
};
