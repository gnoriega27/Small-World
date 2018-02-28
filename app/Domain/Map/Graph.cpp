//
// Created by Philippe Hebert on 2018-02-16.
//
#include <memory>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "Graph.h"

using string = std::string;

namespace SmallWorld{
  namespace Map {
    using edge_vector = std::vector<bool>;

    template <class E>
    Graph<E>::Graph(
      std::vector<std::pair<string, std::shared_ptr<E>>> nodes,
      std::vector<std::pair<string, string>> edges) {
        for(const auto& node : nodes){
          addNode(std::get<0>(node), std::get<1>(node));
        }
        for(const auto& edge : edges){
          addEdge(std::get<0>(edge), std::get<1>(edge));
        }
    };

    /**
     * Returns the number of edges in the Graph
     */
    template <class E>
    std::size_t Graph<E>::size() { return m_size; };

    /**
     * Returns the number of nodes in the Graph
     */
    template <class E>
    std::size_t Graph<E>::order() { return m_nodes.size(); };

    /**
     * Returns whether the Graph is directed or not
     */
    template <class E>
    bool Graph<E>::directed() { return m_directed; };

    /**
     * Node existence lookup based on key of the Node
     * @complexity O(n), Θ(1)
     * @param e Element in the node
     */
    template <class E>
    bool Graph<E>::hasNode(const string& s){
      return m_nodes.find(s) != m_nodes.end();
    };

    /**
     * Node existence lookup based on element on the Node
     * @complexity O(n)
     * @param e Element in the node
     */
    template <class E>
    bool Graph<E>::hasNode(const E& e) {
      for(const auto& node : m_nodes) {
        if(e == *(node.second)){
          return true;
        }
      }
      return false;
    };

    /**
     * Edge existence lookup based on key of the Node
     * @complexity O(n), Θ(1)
     * @param src  source node key
     * @param dest destination node key
     */
    template <class E>
    bool Graph<E>::hasEdge(const string& src, const string& dest) {
      if(!hasNode(src) || !hasNode(dest)) {
        return false;
      }
      return m_matrix[getIndex(src)][getIndex(dest)];
    };

    /**
     * Edge existence lookup based on element of the Node
     * @complexity O(n)
     * @param src  source node element
     * @param dest destination node element
     */
    template <class E>
    bool Graph<E>::hasEdge(const E& src, const E& dest) {
      if(!hasNode(src) || !hasNode(dest)) {
        return false;
      }
      return m_matrix[getIndex(src)][getIndex(dest)];
    };

    /**
     * Adds a node with element e at key key. Expands the matrix to accommodate
     * the new node.
     * @complexity O(n)
     * @param key key of the node
     * @param e   element of the node
     */
    template <class E>
    Graph<E>& Graph<E>::addNode(const string& key, const std::shared_ptr<E> e) {
      if(hasNode(key)){
        throw std::invalid_argument("Graph already has Node '" + key + "'");
      }
      const short index = static_cast<short> (m_matrix.size() + 1);
      m_nodes.insert(std::make_pair(key, std::make_pair(e, index)));
      m_indexes.insert(std::make_pair(index, key));
      for(auto& v : m_matrix){
        v.push_back(false);
      }
      //Initialize all values to false;
      std::vector<bool> edges(m_matrix.size() + 1, false);
      m_matrix.push_back(edges);
      return *this;
    };

    /**
     * Replaces the Node element at key key with element e
     * @complexity O(1)
     * @param key key of the node to replace the element of
     * @param e   element of the node to replace
     */
    template <class E>
    Graph<E>& Graph<E>::replaceNode(const string& key, const std::shared_ptr<E> e) {
      if(!hasNode(key)){
        throw std::invalid_argument("Node '" + key + "' does not exist in Graph");
      }
      std::pair<std::shared_ptr<E>, short>* node = &(m_nodes[key]);
      node->first = e;
      return *this;
    };

    /**
     * Adds an edge from node src to node dest
     * @complexity O(n), Θ(1)
     * @param src  src key
     * @param dest dest key
     */
    template <class E>
    Graph<E>& Graph<E>::addEdge(const string& src, const string& dest) {
      if(!hasNode(src)){
        throw std::invalid_argument("Node '" + src + "' does not exist in Graph");
      }
      if(!hasNode(dest)){
        throw std::invalid_argument("Node '" + dest + "' does not exist in Graph");
      }
      return insertEdge(getIndex(src), getIndex(dest));
    };

    /**
     * Adds an edge from node src to node dest
     * @complexity O(n)
     * @param src  src element
     * @param dest dest element
     */
    template <class E>
    Graph<E>& Graph<E>::addEdge(const E& src, const E& dest) {
      if(!hasNode(src)){
        throw std::invalid_argument("Node '" + src + "' does not exist in Graph");
      }
      if(!hasNode(dest)){
        throw std::invalid_argument("Node '" + dest + "' does not exist in Graph");
      }
      return insertEdge(getIndex(src), getIndex(dest));
    };


    template <class E>
    std::vector<string> Graph<E>::neighbours(const string& node){
      std::vector<string> nbs;
      const std::vector<string> in = inNeighbours(node);
      const std::vector<string> out = outNeighbours(node);
      nbs.insert(nbs.end(), in.begin(), in.end());
      nbs.insert(nbs.end(), out.begin(), out.end());
      return nbs;
    };

    template <class E>
    std::vector<string> Graph<E>::neighbours(const E& e){
      return neighbours(getKey(getIndex(e)));
    };

    template <class E>
    short Graph<E>::degree(const string& node){
      return inDegree(node) + outDegree(node);
    };

    /**
     * Returns an unordered list of nodes
     * @complexity O(order)
     */
    template <class E>
    std::vector<std::pair<string, std::shared_ptr<E>>> Graph<E>::nodes() {
      std::vector<std::pair<string, std::shared_ptr<E>>> nodes;
      nodes.reserve(m_nodes.size());
      short count = 0;
      for(const auto& node : m_nodes) {
        nodes.assign(count++, std::make_pair<string, std::shared_ptr<E>>(node.first, node.second.first));
      }
      return nodes;
    };

    /**
     * Returns an unordered list of nodes
     * @complexity O(order + size)
     */
    template <class E>
    std::vector<std::pair<string, string>> Graph<E>::edges() {
      const short order = m_indexes.size();
      std::vector<std::pair<string, string>> edges;
      edges.reserve(m_size);

      // Build the return value
      if(!m_directed){
        for(const auto& index : m_indexes) {
          // If undirected, only need to read one of the two directions of the edges
          // Which means that if you split the matrix at the diagonal, you can take
          // only the ones at the lower half and you are good
          for(short i = index.first; i < order; ++i){
            if(m_matrix[index.first][i]){
              edges.push_back(std::make_pair<string, string>(index.second, m_indexes[i].second));
            }
          }
        }
      }else{
        using szt = std::vector<int>::size_type;
        for(szt i = 0; i < m_matrix.size(); i++) {
          for(szt j = 0; j < m_matrix[i].size(); j++){
            if(m_matrix[i][j]){
              edges.push_back(std::make_pair<string, string>(m_indexes[i].second, m_indexes[j].second));
            }
          }
        }
      }
      return edges;
    };

    template <class E>
    std::vector<string> Graph<E>::inNeighbours(const string& node){
      using szt = std::vector<int>::size_type;
      std::vector<string> nbs;
      const short index = getIndex(node);
      // Based on the way undirected edges are inserted (src_index < dest_index always)
      const short max = m_directed ? m_matrix.size() : index;
      for(szt i = 0; i < max; i++){
        if(m_matrix[i][index] && !(i == index && !m_reflexive)){
          nbs.push_back(getKey(i));
        }
      }
      return nbs;
    }

    template <class E>
    std::vector<string> Graph<E>::outNeighbours(const string& node){
      using szt = std::vector<int>::size_type;
      std::vector<string> nbs;
      const short index = getIndex(node);
      // Based on the way undirected edges are inserted (src_index < dest_index always)
      const short min = m_directed ? 0 : index;
      for(szt i = min; i < m_matrix.size(); i++){
        if(m_matrix[index][i] && !(i == index && !m_reflexive)){
          nbs.push_back(getKey(i));
        }
      }
      return nbs;
    };

    /**
     * Returns the in degree (edges inbound) of the specified node
     * @param node
     */
    template <class E>
    short Graph<E>::inDegree(const string& node) {
      using szt = std::vector<int>::size_type;
      short deg = 0;
      const short index = getIndex(node);
      // Based on the way undirected edges are inserted (src_index < dest_index always)
      const short max = m_directed ? m_matrix.size() : index;
      for(szt i = 0; i < max; i++){
        if(m_matrix[i][index] && !(i == index && !m_reflexive)){
          ++deg;
        }
      }
      return deg;
    };

    /**
     * Returns the out degree (edges outbound) of the specified node
     * @param node [description]
     */
    template <class E>
    short Graph<E>::outDegree(const string& node) {
      using szt = std::vector<int>::size_type;
      short deg = 0;
      const short index = getIndex(node);
      // Based on the way undirected edges are inserted (src_index < dest_index always)
      const short min = m_directed ? 0 : index;
      for(szt i = min; i < m_matrix.size(); i++){
        if(m_matrix[index][i] && !(i == index && !m_reflexive)){
          ++deg;
        }
      }
      return deg;
    };

    /**
     * Returns the m_matrix numeric index
     * @param key Key of the node
     */
    template <class E>
    short Graph<E>::getIndex(const string& key) {
      return m_nodes.at(key).second;
    };

    /**
     * Returns the m_matrix numeric index
     * @param e Element of the node
     */
    template <class E>
    short Graph<E>::getIndex(const E& e) {
      for(const auto& node : m_nodes) {
        if(e == *(node.second.first)){
          return node.second.second;
        }
      }
    };

    /**
     * Returns the associated key with the numeric index
     * @param index Numeric index of the node
     */
    template <class E>
    string Graph<E>::getKey(const short index) {
      return m_indexes.at(index);
    };

    template <class E>
    Graph<E>& Graph<E>::insertEdge(const short& src_index, const short& dest_index) {
      // If is not directed, add the edge from the node with the lowest index to
      // the largest index (reduces calculations for neighbours and edges)
      if(!m_directed){
        if(src_index < dest_index){
          m_matrix[src_index].at(dest_index) = true;
        }else if(src_index > dest_index){
          m_matrix[dest_index].at(src_index) = true;
        // src == dest thus reflexive
        }else if(m_reflexive){
          m_matrix[src_index].at(src_index) = true;
        }
      }else{
        if(src_index == dest_index && m_reflexive){
          m_matrix[src_index].at(src_index) = true;
        }else{
          m_matrix[src_index].at(dest_index) = true;
        }
      }
      // Increase size
      m_size += 1;
      return *this;
    };
  };

  namespace algorithm {
    using search_set = std::set<string>;
    using forest_map = std::unordered_map<string, std::pair<string, string>>;
    using search_cb = std::function<bool(const string&, const search_set&, const forest_map&)>;

    template <class E>
    std::function<size_t(Map::Graph<E>)> dfs(const string& start, const search_cb& callback) {
      return [start, callback](const Map::Graph<E>& g){
        search_set known;
        forest_map forest;
        return dfs_recurs(g, start, known, forest, callback);
      };
    };

    template <class E>
    std::function<size_t(Map::Graph<E>)> bfs(const string& start, const search_cb& callback) {
      return [start, callback](const Map::Graph<E>& g){
        search_set known;
        forest_map forest;
        return bfs_complete(g, start, known, forest, callback);
      };
    };

    namespace {
      template <class E>
      size_t dfs_recurs(
        const Map::Graph<E>& g, const string& node, search_set& known,
        const forest_map& forest, const search_cb& callback){
          known.insert(node);
          if(callback(node, known, forest)){
            for(const auto& n : g.neighbours(node)){
              if(known.find(n) != known.end()){
                forest[n] = std::make_pair<string, string>(node, n);
                dfs_recurs(g, n, known, forest, callback);
              }
            }
          };
          return known.size();
      };

      template <class E>
      size_t bfs_complete(
        const Map::Graph<E>& g, const string& node, search_set& known,
        const forest_map& forest, const search_cb& callback){
          std::vector<string> level;
          known.insert(node);
          level.push_back(node);
          if(callback(node, known, forest)){
            while(!level.empty()){
              std::vector<string> next_level;
              for(const auto& n : level){
                if(callback(n, known, forest)){
                  for(const auto& nb : g.neighbours()){
                    if(known.find(nb) != known.end()){
                      forest[nb] = std::make_pair<string, string>(n, nb);
                      next_level.push_back(nb);
                    }
                  }
                };
              }
              level = next_level;
            }
          }
          return known.size();
      };
    };
  };
};
