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

string* presort_array(string in_arr[], int len)
{
  return in_arr;
}
