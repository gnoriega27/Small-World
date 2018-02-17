//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_GRAPH_H
#define SMALLWORLD_GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using string = std::string;

namespace SmallWorld{
  namespace Map {
    using edge_vector = std::vector<bool>;

    template <class E>
    class Graph {
    public:
      Graph<E>(std::vector<std::pair<string, E>> nodes, std::vector<std::pair<string, string>> edges);
      std::size_t size();
      std::size_t order();
      bool hasNode(const string& s);
      bool hasNode(const E& e);
      bool hasEdge(const string& src, const string& dest);
      bool hasEdge(const E& src, const E& dest);
      Graph* addNode(const string& key, const E& e);
      Graph* replaceNode(const string& key, const E& e);
      Graph* addEdge(const string& src, const string& dest);
      Graph* addEdge(const E& src, const E& dest);
      std::vector<std::pair<string, E*>> nodes();
      std::vector<std::pair<string, string>> edges();
    private:
      const bool m_directed = false;
      const bool m_reflexive = false;
      const std::unordered_map<string, std::pair<E*, short>> m_nodes;
      const std::unordered_map<short, string*> m_indexes;
      const std::vector<edge_vector*> m_matrix;
      std::size_t m_size;
      short getIndex(const string& key);
      short getIndex(const E& e);
      string getKey(const short index);
      Graph* insertEdge(const short& src_index, const short& dest_index);
    };
  };
};

#endif // SMALLWORLD_GRAPH_H
