#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> res;

    for (int i = 1; i <= n; i++)
    {
 

      bool dividedByThree = !(i % 3);
      bool dividedByFive = !(i % 5);
      string s;

      if(dividedByThree)
      {
        s += "Fizz";
      }

      if (dividedByFive)
      {
        s += "Buzz";
      }

      if (s.empty())
      {
        res.push_back(to_string(i));
      }
      else
      {
        res.push_back(s);
      }

      

    }
    return res;
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

  auto r = s.fizzBuzz(1000);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "[";
  for (auto const& el : r)
  {
    if (el.compare(r.at(0)) != 0) cout << ",";
    cout << el;
  }
  cout << "]";
  cout << endl;
  return 0;
};

