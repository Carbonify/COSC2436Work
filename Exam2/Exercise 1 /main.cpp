#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;


bool check_for_symmetry ( string s )
{
  // Implement the function.
  Stack stack;

  for(int i = 0; i<s.length(); i++) {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
      stack.push(s[i]);
    } else if (s[i] == ')') {
      char lastAdded = stack.pop();
      if(lastAdded != '(')
        return false;

    } else if (s[i] == ']') {
      char lastAdded = stack.pop();
      if(lastAdded != '[')
        return false;

    } else if (s[i] == '}') {
      char lastAdded = stack.pop();
      if(lastAdded != '{')
        return false;
    }
  }
  return stack.isEmpty(); //successful if stack empty
}

int main ( int argc, char **argv)
{
  if ( argc < 2 ) {
    return 0;
  }

  string s1 = argv[1];
  bool flag = check_for_symmetry(s1);
  if ( flag == true ) {
    cout << "Expression " << s1 << " has matching parantheses" << endl;
  }
  else {
    cout << "Expression " << s1 << " does not have matching parantheses" << endl;
  }

  return 0;
}
