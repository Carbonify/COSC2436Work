#include <iostream>
#include <cstdio>
#include <vector>

#include "Graph.hpp"

int main(int argc, char* argv[]) {
  //Implement main function
  using namespace std;

  int numberOfTeamsLeft, empsPerTeam, numberOfTeamsTotal;
  int edgeCheckFails = 0, numToMove = 0;

  cin >> numberOfTeamsLeft;
  numberOfTeamsTotal = numberOfTeamsLeft; //track total

  while(numberOfTeamsLeft > 0) {
    cin >> empsPerTeam;
    Graph thisTeam(empsPerTeam);

    int v1, v2, weight;
    while(true) {
      cin >> v1 >> v2 >> weight;
      if (v1 == -1 && v2 == -1 && weight == -1) { //done declaring edges
        break;
      }
      thisTeam.insertEdge(v1, v2, weight);
    }

    int newV1, newV2, newWeight;
    cin >> newV1 >> newV2 >> newWeight;

    thisTeam.DFS(0);
    if (!thisTeam.edgeCheck()) {
      cout << "No path is formed from each location to every other" << endl;
      edgeCheckFails++;
    } else {
      cout << "A path is formed!" << endl;
      int oldMST = thisTeam.MST();
      cout << "Original MST was: " << oldMST << endl;
      //change and recalc
      thisTeam.insertEdge(newV1, newV2, newWeight);
      int newMST = thisTeam.MST();
      cout << "New MST is: " << newMST << endl;

      if (newMST < oldMST) {
        numToMove++;
        cout << "Employee's office should be moved" << endl;
      } else {
        cout << "Employee's office should NOT be moved" << endl;
      }
    }

    //done setting up team
    numberOfTeamsLeft--;
    cout << endl;
  }

  //final prints
  printf("Number of employees' offices with invalid paths: %d/%d",
         edgeCheckFails,
         numberOfTeamsTotal);
  printf("Number of employees who would benefit from moving offices: %d/%d",
         numToMove,
         numberOfTeamsTotal);

  return 0;
}
