#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string>
#include <gtest/gtest.h>
#include "../../../app/Domain/Map/loader.cpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

TEST(creates_a_connected_graph, small_world_map){
  using SmallWorld::Region;
  using Graph = SmallWorld::Map::Graph<Region>;
  using search_set = std::set<string>;
  using forest_map = std::unordered_map<string, std::pair<string, string>>;
  char buff[PATH_MAX];
  realpath("./map.json", buff);
  if(buff == NULL){
    cout << "Null pointer" << endl;
  }else{
    string path = buff;
    cout << "path: " << path << endl;
  }



  // std::cout << "path: " << path << std::endl;
  //
  // std::shared_ptr<Graph> g = SmallWorld::Map::loadMap(path);
  // const size_t order = g->order();
  // const size_t dfs_order = SmallWorld::Map::algorithm::dfs<Region>(
  //   "r1",
  //   [](const string&, const search_set&, const forest_map&) -> bool { return true; }
  // )(*g);
  // ASSERT_EQ(order, dfs_order);
}
