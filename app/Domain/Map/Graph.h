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
      std::size_t size() const;
      std::size_t order() const;
      bool directed() const;
      bool hasNode(const string& s) const;
      bool hasNode(const E& e) const;
      bool hasEdge(const string& src, const string& dest) const;
      bool hasEdge(const E& src, const E& dest) const;
      Graph<E>& addNode(const string& key, const std::shared_ptr<E> e);
      Graph<E>& replaceNode(const string& key, const std::shared_ptr<E> e);
      Graph<E>& addEdge(const string& src, const string& dest);
      Graph<E>& addEdge(const E& src, const E& dest);
      std::vector<string> neighbours(const string& node) const;
      std::vector<string> neighbours(const E& e) const;
      short degree(const string& node) const;
      short degree(const E& e) const;
      std::vector<std::pair<string, std::shared_ptr<E>>> nodes() const;
      std::vector<std::pair<string, string>> edges() const;
    private:
      const bool m_directed = false;
      const bool m_reflexive = false;
      std::unordered_map<string, std::pair<std::shared_ptr<E>, short>> m_nodes;
      std::unordered_map<short, string> m_indexes;
      std::vector<edge_vector> m_matrix;
      std::size_t m_size;
      std::vector<string> inNeighbours(const string& node) const;
      std::vector<string> outNeighbours(const string& node) const;
      short inDegree(const string& node) const;
      short outDegree(const string& node) const;
      short getIndex(const string& key) const;
      short getIndex(const E& e) const;
      string getKey(const short index) const;
      Graph<E>& insertEdge(const short& src_index, const short& dest_index);
    };

    namespace algorithm {
      using search_set = std::set<string>;
      using forest_map = std::unordered_map<string, std::pair<string, string>>;
      using search_cb = std::function<bool(const string&, search_set&, const forest_map&)>;

      template <class E>
      std::function<size_t(Graph<E>)> dfs(const string& start, const search_cb& callback);

      template <class E>
      std::function<size_t(Graph<E>)> bfs(const string& start, const search_cb& callback);

      namespace {
        template <class E>
        size_t dfs_recurs(
          const Graph<E>& g, const string& node, search_set& known,
          forest_map& forest, const search_cb& callback
        );

        template <class E>
        size_t bfs_complete(
          const Graph<E>& g, const string& node, search_set& known,
          forest_map& forest, const search_cb& callback
        );
      }
    }
  }
}

#endif // SMALLWORLD_GRAPH_H
