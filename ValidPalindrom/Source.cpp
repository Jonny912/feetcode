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
  bool isPalindrome(string s) {
    string::iterator It1 = s.begin();
    string::iterator It2 = s.end() - 1;
    while (It1 < It2) {
      if (!isalnum(*It1)) {
        It1++;
      }
      else if (!isalnum(*It2)) {
        It2--;
      }
      else if (tolower(*It1) != tolower(*It2)) {
        return false;
      }
      else {
        It1++;
        It2--;
      }
    }
    return true;
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

  /* Recording the starting clock tick.*/
  start = clock();

  Solution s;
  auto res = s.isPalindrome("A man, a plan, a canal : Panama");

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
