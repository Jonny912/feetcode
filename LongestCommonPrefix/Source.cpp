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
  string longestCommonPrefix(vector<string>& strs) {
    // Solution #1 "2 loops" => Time: O(n*m), Space: O(1)
    //if (strs.size() == 1) return strs[0];
    //for (int i = 0; i <= strs[0].length(); i++) { // loop trought chars
    //  for (int k = 0; k < strs.size() - 1; k++) { // loop trought vectors
    //    if (strs[k].empty() || strs[k+1].empty() 
    //      || strs[k][i] != strs[k + 1][i]  || strs[k][i] == '\0') {
    //      return strs[0].substr(0, i);
    //    }
    //  }
    //}
    //return "";
    // Solution #2 "Sort" => Time O (N*M*Log(M)) Space: O(1)
    if (strs.size() == 1) return strs[0];
    sort(strs.begin(), strs.end());
    string prefix;
    const auto& first = strs[0];
    const auto& last = strs[strs.size() - 1];
    auto shorterStringLen = min({ first.size(), last.size() });
    for (int i = 0; i <= shorterStringLen; i++) {
      if (first.empty() || last.empty() 
        || first[i] != last[i] || first[i] == '\0') {
        return strs[0].substr(0, i);
      }
    }
    return "";
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

  vector<string> v =  { "c", "c" };

  /* Recording the starting clock tick.*/
  start = clock();

  Solution s;
  auto res = s.longestCommonPrefix(v);

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
