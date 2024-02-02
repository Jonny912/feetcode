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
  void reverseString(vector<char>& str) {
    // Solution #1 "STL algorithm REVERSE" => Time: O(n), Space: O(1)
    //reverse(str.begin(), str.end());
     
    // Solution #2 => Time: O(n), Space: O(1)
    auto first = str.begin();
    auto last = str.end();
    while (first != last && first != --last) {
      swap(*first++, *last);
    }
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

  // Make test input
  string s1 = "hello world";
  vector<char> str;
  for (auto c : s1) {
    str.push_back(c);
  }
  //vector<char> str2 = { 'h','e','l','l','o' };

  Solution s;
  s.reverseString(str);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  string reversedString;
  reversedString.assign(&str.at(0), str.size());
  cout << reversedString.c_str() << endl;

  return 0;
};
