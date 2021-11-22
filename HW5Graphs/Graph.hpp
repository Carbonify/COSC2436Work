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
    //Implement function
  }

  void resetVisited() {
    //Implement function
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
