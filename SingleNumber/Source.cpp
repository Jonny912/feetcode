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
  int singleNumber(vector<int>& nums) {
    // Time = O(n*log(n)), Space = O(1); 
    //sort(nums.begin(), nums.end());
    //for (auto cur = nums.begin(); cur != nums.end(); cur += 2)
    //{
    //  auto next = cur + 1;
    //  if ((next == nums.end()) || (*cur != *next))
    //  {
    //    return *cur;
    //  }
    //}
    // Time = O(n), Space = O(n);
    unordered_set<int> s;
    for (auto cur = nums.begin(); cur != nums.end(); cur++)
    {
      auto res = s.insert(*cur);
      if (!res.second)
      {
        s.erase(*cur);
      }
    }
    return *s.begin();
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

  vector<int> v = { 1, 2, 3, 4, 1, 2, 3};
  auto r = s.singleNumber(v);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "result = " << r << endl;

  return 0;
};

