#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "BSTUtils.h"

string* file_to_array(string f_name, int *l)
{
  //implement function
  auto result = new std::vector<string>();
  string line;

  std::ifstream file(f_name);
  if (file.is_open()) {
    while (!file.eof()) {
      file >> line;
      result->push_back(line);
    }
  }
  *l = result->size();
  return result->data();
}

void array_to_bst(string key_arr[], int len, BSTree* i_bst)
{
  //implement function
  for (int i = 0; i < len; i++) {
    i_bst->addNode(key_arr[i]);
  }
}

BSTNode* presortArrayHelper(string* array, int start, int end) {
  if (start > end)
    return nullptr;

  int middle = (start + end)/2;

}

void sortArrayAscending(string* array, int length) {
  for(int i=0; i<length; i++) {
    for(int j=i; j<length; j++) {
      if (array[i] > array[j]) {
        string temp;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

string* presort_array(string in_arr[], int len)
{
  sortArrayAscending(in_arr, len); //sort array ascending first
  return nullptr;
}
