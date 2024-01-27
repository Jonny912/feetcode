#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  // 1 2 3 4 5 6
  // 6 1 2 3 4 5 
  void rotate(vector<int>& nums, int k)
  {
    // Fisrt solution

  if (k %= nums.size())
      std::rotate(nums.begin(), std::prev(nums.end(), k), nums.end());

  
  // second solution
  //    k %= nums.size();
//    reverse(nums.begin(), nums.end());
//    reverse(nums.begin(), nums.begin() + k);
//    reverse(nums.begin() + k, nums.end());

  // 3d solution
  //    k %= nums.size();

//  rotateRange(nums.begin(), nums.end() - 1);
//  rotateRange(nums.begin(), nums.begin() + k - 1);
//  rotateRange(nums.begin() + k, nums.end() - 1);
  //}
//  void rotateRange(vector<int>::iterator first, vector<int>::iterator last)
//  {
//    for (;first < last; first++, last--)
//   {
//    swap(*first, *last);
//    }
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

  vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
  s.rotate(v, 3);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "[ ";
  for (auto const& m : v)
  {
    cout << m << " ";
  }
  cout << "]" << endl;
  return 0;
};

