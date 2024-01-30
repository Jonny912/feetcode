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
  vector<int> twoSum(vector<int>& nums, int target) {
    //for (int i = 0; i < nums.size(); i++) {
    //  for (int j = i +1; j < nums.size(); j++) {
    //    if (nums[i] == target - nums[j])
    //    {
    //      return { i, j };
    //    }
    //  }
    //}
    //return {};

    unordered_map<int, int> mymap;
    for (int i = 0; i < nums.size(); i++) {
      mymap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      auto comp = target - nums[i];
      if (mymap[comp] && mymap[comp] != i)
      {
        return { i, mymap[comp] };
      }
    }
    return { 0,0 };
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
  vector<int> list = { 3, 2, 4 };
  //for (int i = 0; i < 1000000; i++)
  //{
  //  list.push_back(GetRandomNumber(0, 10));
  //}
  Solution s;
  auto res = s.twoSum(list, 6);

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

