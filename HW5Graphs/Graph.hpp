#pragma once
#include <iostream>
#include <climits>
#include <vector>
#include <stack>

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
    matrix.at(v1).at(v2) = weight;
    matrix.at(v2).at(v1) = weight;
  }

  void DFS(const int vertex) {
    //Implement function
    auto dfsStack = std::stack<int>();

    dfsStack.push(vertex);
    resetVisited();

    while (!dfsStack.empty()) {
      int currentV = dfsStack.top();
      dfsStack.pop();
      if (!visited.at(currentV)) {
        visited.at(currentV) = true;

        //for each vertex adjV adjacent to currentV
        //Push adjV to stack
        for(const int& v : matrix.at(currentV)) {
          if (v > 0) dfsStack.push(v);
        }
      }
    }
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
