#pragma once
#include <iostream>
#include <climits>
#include <vector>

class Graph {

 private:
  std::vector<std::vector<int>> matrix;
  int size;
  std::vector<bool> visited;

 public:
  Graph(const int mySize) : size(mySize) {
    using namespace std;
    //Implement function
    matrix = vector<vector<int>>(mySize, vector<int>(mySize, 0));
    visited = vector<bool>(mySize, false);
  }

  void resetVisited() {
    //Implement function
    for(unsigned long i = 0; i < visited.size(); i++) {
      visited.at(i) = false;
    }
  }

  void insertEdge(const int v1, const int v2, const int weight) {
    //Implement function
  }

  void DFS(const int vertex) {
    //Implement function
  }

  bool edgeCheck() {
    //Implement function
    for(const auto& x : visited) {
      if (!x) {
        return false;
      }
    }
    return true;
  }

  int MST() {
    //Implement function
  }
};
