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
  int reverseInteger(int x) {
    // Solution #1 
    auto s = to_string(x);
    vector<char> v(s.begin(), s.end()); v.push_back(0);
    auto first = v.begin();
    if (*first == '-') {
      first++;
    }
    std::reverse(first, v.end() - 1);
    auto i = atoll(& v[0]);

    if (i > INT32_MAX || i < INT32_MIN) {
      return 0;
    }
    return i;
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

  // Make test input
  int x = 1534236469;
  Solution s;
  auto res = s.reverseInteger(x);

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
