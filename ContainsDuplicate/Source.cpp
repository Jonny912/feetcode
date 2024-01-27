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
  bool containsDuplicate(vector<int>& nums) 
  {
    // Time O = n log n, Space: O(1)
    //sort(nums.begin(), nums.end());
    //for (auto i = nums.begin(); i != nums.end()-1; i++)
    //{
    //  if (*i == *(i + 1))
    //    return true;
    //}
    //return false;
    
     // Time O(n) Mem O(n)
    unordered_set<int> numsSet;
    for (auto i = nums.begin(); i != nums.end(); i++)
    {
      auto res = numsSet.insert(*i);
      if (res.second == false)
      {
        return true;
      }
    }
    return false;
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

  vector<int> v;
  for (int i = 1; i < 100000; i++)
  {
    v.push_back(i);
  }
  auto r = s.containsDuplicate(v);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "result = " << (r ? "true" : "false") << endl;

  return 0;
};

