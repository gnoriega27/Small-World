//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_GRAPH_H
#define SMALLWORLD_GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>

using string = std::string;

namespace SmallWorld{
  namespace Map {
    template <class E>
    class Graph {
    public:
      Graph<E>(std::vector<std::tuple<string, E>> nodes, std::vector<std::tuple<string, string>> edges);
      std::size_t size();
      std::size_t order();
      bool hasNode(const string& s);
      bool hasNode(const E& e);
      bool hasEdge(const string& src, const string& dest);
      bool hasEdge(const E& src, const E& dest);
      Graph addNode(const string& key, const E& e);
      Graph replaceNode(const string& key, const E& e);
      Graph addEdge(const string& src, const string& dest);
      Graph addEdge(const E& src, const E& dest);
      std::vector<std::tuple<string, string>>
      std::vector<std::tuple<string, E>> nodes();
      std::vector<std::tuple<string, string>> edges();
    private:
      short getIndex(const string& key);
      short getIndex(const E& e);
      const bool m_directed = false;
      const std::unordered_map<string, E> m_nodes;
      const std::unordered_map<string, short> m_indexes;
      const std::vector<std::vector<bool>> m_matrix;
      std::size_t m_size;
    };
  };
};

#endif // SMALLWORLD_GRAPH_H
