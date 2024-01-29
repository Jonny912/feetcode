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
  vector<int> plusOne(vector<int>& digits) {
    for (char i = static_cast<char>(digits.size()-1); i >= 0; i--) {
      auto digit = digits[i];
      digit++;
      if (digit <= 9) {
        digits[i] = digit;
        break;
      }
      else
      {
        digit %= 10;
        digits[i] = digit;
        if (i == 0) {
          digits.emplace(digits.begin(), 1);
        }

      }
    }
    return digits;
  }
};
int GetRandomNumber(int min, int max)
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
  vector<int> bigInt = { 9, 9, 9 };
  Solution s;
  auto res = s.plusOne(bigInt);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  for (auto r : res)
  {
    cout << r << " ";
  }

  return 0;
};

