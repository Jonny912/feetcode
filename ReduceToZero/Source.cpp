#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int numberOfSteps(int num)
  {
    char steps = 0;
    while (num != 0)
    {
      steps++;
      if (num % 2 == 0)
      {
        num /= 2;
      }
      else
      {
        num -= 1;
      }
    }
    return steps;
  }
};

int main()
{
  Solution s;

  /* clock_t clock(void) returns the number of clock ticks
    elapsed since the program was launched.To get the number
    of seconds used by the CPU, you will need to divide by
    CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical
    32 bit system.  */
  clock_t start, end;

  /* Recording the starting clock tick.*/
  start = clock();

  auto numnerOfSteps = s.numberOfSteps(14);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  printf("steps amount is = %d\n", numnerOfSteps);
  return 0;
};

