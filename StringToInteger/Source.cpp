#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    long long result = 0;
    int multiplier = 1;
    int i = 0;
    while (isspace(s[i])) { i++; }
    if (s[i] == '-' || s[i] == '+') {
      multiplier = (s[i++]== '-') ? -1 : 1;
    }

    while (i < s.length() && isdigit(s[i])) {
      result = result * 10 + s[i++] - '0';
      if (result * multiplier > INT32_MAX) {
        return INT32_MAX;
      }
      if (result * multiplier < INT32_MIN) {
        return INT32_MIN;
      }
    }
    return static_cast<int>(result*multiplier);
  }
};

static int GetRandomNumber(int min, int max)
{
  // Get a random number - formula
  int num = min + rand() % (max - min + 1);

  return num;
}

int main()
{
  // Set the random number generator
  srand(static_cast<unsigned int>(time(nullptr)));

  /* clock_t clock(void) returns the number of clock ticks
    elapsed since the program was launched.To get the number
    of seconds used by the CPU, you will need to divide by
    CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical
    32 bit system.  */
  clock_t start, end;

  /* Recording the starting clock tick.*/
  start = clock();

  Solution s;
  auto res = s.myAtoi("   -42");

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << res << endl;

  return 0;
};
