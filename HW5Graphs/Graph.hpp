#pragma once
#include <vector>
#include <stack> //for DFS
#include <queue> //for MST
#include <cstdlib> //for rand()

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
        for(const int& v : matrix.at(currentV)) {
          if (v > 0) dfsStack.push(v);
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
    //Implement function
    using namespace std;

    //typedefs for readability
    typedef pair<int,int> intPair;
    typedef vector<intPair> vectorIntPair;

    int randomEntry = rand() % size;
    int MSTCost = 0;

    priority_queue<intPair, vectorIntPair, greater<intPair>> prioQueue;
    prioQueue.push(make_pair(0, randomEntry));

    resetVisited();

    while(!prioQueue.empty()) {
      intPair item = prioQueue.top();
      prioQueue.pop();
      int cost = item.first;
      int nodeIndex = item.second;

      if (!visited.at(nodeIndex)) {
        MSTCost += cost;
        visited.at(nodeIndex) = true;

        for (int i = 0; i < size; i++) {
          int weightAtI = matrix.at(0).at(i);
          if (weightAtI > 0 && !visited.at(i)) {
            prioQueue.push(make_pair(weightAtI, i));
          }
        }
      }
    }
    return MSTCost;
  }
};
