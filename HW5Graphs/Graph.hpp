#pragma once
#include <vector>
#include <stack> //for DFS
#include <climits> //for MAX_INT

class Graph {

private:
  std::vector<std::vector<int>> matrix;
  int size;
  std::vector<bool> visited;

public:
  Graph(const int mySize) : size(mySize) {
    using namespace std;
    //Create two vectors, set insides to 0 and false respectively
    matrix = vector<vector<int>>(mySize, vector<int>(mySize, 0));
    visited = vector<bool>(mySize, false);
  }

  void resetVisited() {
    //Set all values to false
    for(unsigned long i = 0; i < visited.size(); i++) {
      visited.at(i) = false;
    }
  }

  void insertEdge(const int v1, const int v2, const int weight) {
    //Implement function
    matrix.at(v1).at(v2) = weight;
    matrix.at(v2).at(v1) = weight; //backwards as well because undirected
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

        //for each vertex adjV adjacent to currentV, push adjV to stack
        for(int i = 0; i < size; i++) {
          if (matrix.at(currentV).at(i) > 0) dfsStack.push(i); //push if weight > 0, aka adjacent
        }
      }
    }
  }

  bool edgeCheck() {
    //True if all values in visited are true
    for(const auto& x : visited) {
      if (!x) {
        return false;
      }
    }
    return true;
  }

  int MST() {
    //Calculates MST of `matrix` via prim's algorithm.
    resetVisited();

    int MSTCost = 0;
    int edges = 0;
    int locationToVisit = 0;
    int bestX, bestY;

    visited.at(0) = true;

    while (edges < size - 1) {
      int minimum = INT_MAX;
      for (int i = 0; i < size; i++) {
        if (visited.at(i)) {
          for (int j = 0; j < size; j++) {
            int weight = matrix.at(i).at(j);
            if (!visited.at(j) && weight > 0) { //not visited, has connection
              if (minimum > weight) { //connection is cheapest
                minimum = weight;
                bestX = i;
                bestY = j;
                locationToVisit = j;
              }
            }
          }
        }
      }
      edges++;
      MSTCost += matrix.at(bestX).at(bestY);
      visited.at(locationToVisit) = true;
    }
    return MSTCost;
  }
};
