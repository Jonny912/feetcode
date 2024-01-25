#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include<random>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums)
  {
    
    for(auto ptr = nums.begin(); ptr != nums.end(); ptr++)
    {
      auto ptr2 = ptr;
      ptr2++;
      while (ptr2 != nums.end() && *ptr2 == *ptr)
      {
        ptr2++;
      }
      nums.erase(ptr + 1, ptr2);
    }
    return static_cast<int>(nums.size());
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

  srand(static_cast<unsigned int>(time(0)));
  vector<int> v;// { 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 9, 10 };
  for (int i = 1; i <= 8; i++)
  {
    int count = rand() % 10 + 1;
    for (int k = 0; k < count; k++) v.push_back(i);
  }
  auto k = s.removeDuplicates(v);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  printf("k = %d\n", k);
  return 0;
};

