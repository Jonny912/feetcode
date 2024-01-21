#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts)
  {
    int richestWealth = 0;
    for (auto const& account : accounts)
    {
      int accountMoney = 0;
      for (auto const& money : account)
      {
        accountMoney += money;
      }
      if (richestWealth < accountMoney)
      {
        richestWealth = accountMoney;
      }
    }
    return richestWealth;
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

  vector<vector<int>> accounts = { { 1,2,3 }, { 5,2,1 }, {3,-1, 12} };
  auto r = s.maximumWealth(accounts);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  printf("result INT = %d\n", r);
  return 0;
};

