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
  Graph(int mySize) {
    using namespace std;
    //Implement function
    matrix = vector<vector<int>>(mySize);
    visited = vector<bool>(mySize, false);
  }

  void resetVisited() {
    //Implement function
    for(int i = 0; i < visited.size(); i++) {
      visited.at(i) = false;
    }
  }

  void insertEdge(int v1, int v2, int weight) {
    //Implement function
  }

  void DFS(int vertex) {
    //Implement function
  }

  bool edgeCheck() {
    //Implement function
  }

  int MST() {
    //Implement function
  }
};
