//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_GRAPH_H
#define SMALLWORLD_GRAPH_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <utility>

using string = std::string;

namespace SmallWorld{
  namespace Map {
    using edge_vector = std::vector<bool>;

    template <class E>
    class Graph {
    public:
      Graph<E>(std::vector<std::pair<string, std::shared_ptr<E>>> nodes, std::vector<std::pair<string, string>> edges);
      std::size_t size();
      std::size_t order();
      bool directed();
      bool hasNode(const string& s);
      bool hasNode(const E& e);
      bool hasEdge(const string& src, const string& dest);
      bool hasEdge(const E& src, const E& dest);
      Graph* addNode(const string& key, const std::shared_ptr<E> e);
      Graph* replaceNode(const string& key, const std::shared_ptr<E> e);
      Graph* addEdge(const string& src, const string& dest);
      Graph* addEdge(const E& src, const E& dest);
      std::vector<string> neighbours(const string& node);
      std::vector<string> neighbours(const E& e);
      short degree(const string& node);
      short degree(const E& e);
      std::vector<std::pair<string, std::shared_ptr<E>>> nodes();
      std::vector<std::pair<string, string>> edges();
    private:
      const bool m_directed = false;
      const bool m_reflexive = false;
      const std::unordered_map<string, std::pair<std::shared_ptr<E>, short>> m_nodes;
      const std::unordered_map<short, string> m_indexes;
      const std::vector<edge_vector> m_matrix;
      std::size_t m_size;
      std::vector<string> inNeighbours(const string& node);
      std::vector<string> outNeighbours(const string& node);
      short inDegree(const string& node);
      short outDegree(const string& node);
      short getIndex(const string& key);
      short getIndex(const E& e);
      string getKey(const short index);
      Graph* insertEdge(const short& src_index, const short& dest_index);
    };

    namespace algorithm {
      using search_set = std::set<string>;
      using forest_map = std::unordered_map<string, std::pair<string, string>>;
      using search_cb = std::function<bool(const string&, const search_set&, const forest_map&)>;

      template <class E>
      std::function<size_t(Graph<E>)> dfs(const string& start, const search_cb& callback);

      template <class E>
      std::function<size_t(Graph<E>)> bfs(const string& start, const search_cb& callback);

      namespace {
        template <class E>
        size_t dfs_recurs(
          const Graph<E>& g, const string& node, const search_set& known,
          const forest_map& forest, const search_cb& callback
        );

        template <class E>
        size_t bfs_complete(
          const Graph<E>& g, const string& node, const search_set& known,
          const forest_map& forest, const search_cb& callback
        );
      };
    };
  };
};

#endif // SMALLWORLD_GRAPH_H
