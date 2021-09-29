#include <cstdio>

int getSum (const int val, const int dist, const int runningTotal = 0)
{
  // Implement function

  /*
    Write a recursive function get Sum(int value, int distance) that provides the sum of all even values up to a certain distance from a starting value, but counting backwards. For example,

    getSum( 12, 5 )

    will consider the values 12, 11, 10, 9, and 8 (i.e. 5 values including the starting value), but the sum returned will only use the even values in that sequence, i.e. 12+10+8 = 30

    Input and distance values provided are guaranteed to be larger or equal to zero.
  */

  if(dist == 0) {
    return runningTotal;
  }

  if(val == 0) {
    return 0;
  }

  if(val % 2 == 0) { //even, so add it to the total we're passing forward
    return getSum(val-1, dist-1, runningTotal+ val);
  } else {
    return getSum(val-1, dist-1, runningTotal); //else just continue with the total unchanged
  }
}


int main ( int argc, char **argv )
{

  printf("Input is 12, 5, output is %d, should be 30\n", getSum(12,5));
  printf("Input is 120, 10, output is %d, should be 580\n", getSum(120,10));
  printf("Input is 0, 10, output is %d, should be 0\n", getSum(0,10));

  return 0;
}
