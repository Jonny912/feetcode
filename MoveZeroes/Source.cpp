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
  void moveZeroes(vector<int>& nums) {

//#if __cplusplus >= 202002L
//
//   // C++20
//    auto count = std::erase(nums, 0);
//#else
//    // C++14
//    auto count = std::count(nums.begin(), nums.end(), 0);
//    nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
//#endif
//    while (count--) {
//      nums.push_back(0);
//    }
      int nonzeroIndex = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] != 0)
        {
          swap(nums[i], nums[nonzeroIndex]);
          nonzeroIndex++;
        }
      }
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
  vector<int> list = { 0, 1, 3, 0, 9, 12 };
  //for (int i = 0; i < 1000000; i++)
  //{
  //  list.push_back(GetRandomNumber(0, 10));
  //}
  Solution s;
  s.moveZeroes(list);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  //for (auto r : list)
  //{
  //  cout << r << " ";
  //}

  return 0;
};

