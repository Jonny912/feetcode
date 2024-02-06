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
  int strStr(string haystack, string needle) {
    // Fast STL solution => Time: O(n), Space: O(1)
    // return static_cast<int>(haystack.find(needle));

    // Sliding window algorithm => Time: O(n), Space: O(1) 
    if (haystack.size() < needle.size()) {
      return -1;
    }
    unsigned short i = 0;
    while (i == 0 || i <= (haystack.size() - needle.size())+1) {
      unsigned short k = 0;
      unsigned short j = i;
      while (k < needle.size()) {
        if (haystack[j] == needle[k]) {
          j++; k++;
          if (k == needle.size()) {
            return static_cast<int>(i);
          }
          continue;
        }
        else {
          i++;
          break;
        }
      }
    }
    return -1;
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
  auto res = s.strStr("mississippi", "issip");

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
