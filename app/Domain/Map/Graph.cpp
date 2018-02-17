//
// Created by Philippe Hebert on 2018-02-16.
//
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
      std::vector<std::pair<string, E>> nodes,
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
      return *(m_matrix[getIndex(src)])[getIndex(dest)];
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
      return *(m_matrix[getIndex(src)])[getIndex(dest)];
    };

    /**
     * Adds a node with element e at key key. Expands the matrix to accommodate
     * the new node.
     * @complexity O(n)
     * @param key key of the node
     * @param e   element of the node
     */
    template <class E>
    Graph<E>* Graph<E>::addNode(const string& key, const E& e) {
      if(hasNode(key)){
        throw std::invalid_argument("Graph already has Node '" + key + "'");
      }
      const short index = static_cast<short> (m_matrix.size() + 1);
      m_nodes[key] = std::make_pair<E*, short>(&e, index);
      m_indexes[index] = &key;
      for(auto& v : m_matrix){
        v->push_back(false);
      }
      //Initialize all values to false;
      std::vector<bool> edges(m_matrix.size() + 1, false);
      m_matrix.push_back(&edges);
      return &this;
    };

    /**
     * Replaces the Node element at key key with element e
     * @complexity O(1)
     * @param key key of the node to replace the element of
     * @param e   element of the node to replace
     */
    template <class E>
    Graph<E>* Graph<E>::replaceNode(const string& key, const E& e) {
      if(!hasNode(key)){
        throw std::invalid_argument("Node '" + key + "' does not exist in Graph");
      }
      std::pair<E*, short>* node = &(m_nodes[key]);
      node->first = e;
      return &this;
    };

    /**
     * Adds an edge from node src to node dest
     * @complexity O(n), Θ(1)
     * @param src  src key
     * @param dest dest key
     */
    template <class E>
    Graph<E>* Graph<E>::addEdge(const string& src, const string& dest) {
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
    Graph<E>* Graph<E>::addEdge(const E& src, const E& dest) {
      if(!hasNode(src)){
        throw std::invalid_argument("Node '" + src + "' does not exist in Graph");
      }
      if(!hasNode(dest)){
        throw std::invalid_argument("Node '" + dest + "' does not exist in Graph");
      }
      return insertEdge(getIndex(src), getIndex(dest));
    };

    /**
     * Returns an unordered list of nodes
     * @complexity O(order)
     */
    template <class E>
    std::vector<std::pair<string, E*>> Graph<E>::nodes() {
      std::vector<std::pair<string, E*>> nodes;
      nodes.reserve(m_nodes.size());
      short count = 0;
      for(const auto& node : m_nodes) {
        nodes.assign(count++, std::make_pair<string, E>(node.first, &(node.second)));
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
        size_t count = 0;
        for(const auto& index : m_indexes) {
          // If undirected, only need to read one of the two directions of the edges
          // Which means that if you split the matrix at the diagonal, you can take
          // only the ones at the lower half and you are good
          for(short i = index.first; i < order; ++i){
            if(*(m_matrix[index.first])[i]){
              edges.assign(count++, std::make_pair<string, string>(index.second, m_indexes[i].second));
            }
          }
        }
      }else{
        using szt = std::vector<int>::size_type;
        size_t count = 0;
        for(szt i = 0; i != m_matrix.size(); i++) {
          for(szt j = 0; j != m_matrix[i].size(); j++){
            if(*(m_matrix[i])[j]){
              std::pair<string, string> tup (m_indexes[i].second, m_indexes[j].second);
              edges.assign(count++, tup);
            }
          }
        }
      }
      return edges;
    };

    template <class E>
    short Graph<E>::getIndex(const string& key) {
      return m_nodes.at(key).second;
    };

    template <class E>
    short Graph<E>::getIndex(const E& e) {
      for(const auto& node : m_nodes) {
        if(e == node.second.first){
          return node.second.second;
        }
      }
    };

    template <class E>
    string Graph<E>::getKey(const short index) {
      return *(m_indexes.at(index));
    };

    template <class E>
    Graph<E>* Graph<E>::insertEdge(const short& src_index, const short& dest_index) {
      // If is not directed, add the edge from the node with the lowest index to
      // the largest index (reduces calculations for neighbours and edges)
      if(!m_directed){
        if(src_index < dest_index){
          *(m_matrix[src_index])[dest_index] = true;
        }else if(src_index > dest_index){
          *(m_matrix[dest_index])[src_index] = true;
        // src == dest thus reflexive
        }else if(m_reflexive){
          *(m_matrix[src_index])[src_index] = true;
        }
      }else{
        if(src_index == dest_index && m_reflexive){
          *(m_matrix[src_index])[src_index] = true;
        }else{

        }
      }
      // Increase size
      m_size += 1;
      return &this;
    };
  };
};
