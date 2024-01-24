#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string merged;
    auto max = std::max(word1.length(), word2.length());

    for (int i = 0; i < max; i++)
    {
      if (i < word1.length())
      {
        merged += word1.at(i);
      }
      if (i < word2.length())
      {
        merged += word2.at(i);
      }
    }
    return merged;
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

  auto res = s.mergeAlternately("ab", "pqra");

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "result = " << res << endl;
  return 0;
};

