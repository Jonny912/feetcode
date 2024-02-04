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
  //// Solution #1 "Calculate characters frequency" => Time: Linear O(n), Space: Constant O(1)
    using freq = unsigned short[26];
    bool isAnagram(string s, string t) {
      freq s_f = { 0 };
      freq t_f = { 0 };
      calcFreq(s, s_f);
      calcFreq(t, t_f);
  
      auto lettersAmount = sizeof(freq) / sizeof(unsigned);
      for (int i = 0; i < lettersAmount; i++) {
        if (s_f[i] != t_f[i]) {
          return false;
        }
      }
      return true;
    }
  private:
    void calcFreq(string s, freq &f) {
      for (auto c : s) {
        f[c - 'a']++;
      }
    }
  // Solution #2 "Sort" => Time: Linearithmic O(n*log(n)), Space: O(1)
  //bool isAnagram(string s, string t) {
  //  if (s.length() != t.length()) {
  //    return false;
  //  }
  //  sort(s.begin(), s.end());
  //  sort(t.begin(), t.end());
  //  if (s.compare(t) != 0) {
  //    return false;
  //  }
  //  return true;
  //}
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
  Solution s;
  auto res = s.isAnagram("anagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagram", "nagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaram");
  for (int i = 0; i < 100000; i++) {
    res = s.isAnagram("anagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagram", "nagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaram");
  }

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << (res ? "true" : "false") << endl;

  return 0;
};
