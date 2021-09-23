#include <iostream>

using namespace std;

bool isPrime(const int testNum, const int divisor = 2) {

  if(testNum == 1) {
    return false;
  }
  if(testNum == 2 || testNum == divisor) {
    return true;
  }
  if(testNum % divisor == 0 && testNum != divisor) {
    return false;
  }

  return isPrime(testNum, divisor + 1);
}

int main () {


  /*

    Complete the recursive function isPrime to determine if a number is prime (divisible only by 1 or itself).

    Hints:

    This function takes 2 arguments: the number to test, and a possible divisor. The divisor has a

    default value of 2 (the first one that is tested), so the function isPrime can be called using only the number to be tested as argument, such as

  */

  for(int i = 0; i < 50; i++) {
    cout << "Is " << i << " prime? " << isPrime(i) << endl;
  }

  /*

    You can assume this function will be used to test only positive (>0) integer numbers
    Watch out for special cases: 1 (not prime) and 2 (prime)

  */


  return 0;
}
