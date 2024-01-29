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
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) const {
    return solution2(nums1, nums2);
  }
  
  vector<int> solution1(vector<int>& nums1, vector<int>& nums2) const
  {
    // Solution #1 "Hash table for smaller vector" => Time: O(n1+n2), Space: O(min(n1,n2))
    unordered_multiset<int> s;
    vector<int>* p = nullptr;
    if (nums1.size() > nums2.size()) {
      p = &nums1; // bigger vector put to the pointer
      makeSet(nums2, s); // make the set from smaller vector 
    }
    else {
      p = &nums2;
      makeSet(nums1, s);
    }

    vector<int> result;

    for (const auto i : *p) {
      auto pos = s.find(i);
      if (pos != s.end()) {
        result.push_back(i);
        s.erase(pos);
      }
    }

    p = nullptr;

    return result;
  }

  vector<int> solution2(vector<int>& nums1, vector<int>& nums2) const {
    // Solution #2 "Sort" => Time: O(n log n), Space O(n)
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    auto size1 = nums1.size();
    auto size2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < size1 && j < size2) {
      if (nums1[i] < nums2[j]) {
        i++;
        continue;
      }
      else if (nums1[i] > nums2[j]) {
        j++;
        continue;
      }
      result.push_back(nums1[i]);
      i++;
      j++;
    }

    return result;
  }

  vector<int> solution3(vector<int>& nums1, vector<int>& nums2) const {
    // Solution #3 "STL using std::set_intersection" => Time: O(n log n), Space: O(n))
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    std::set_intersection(nums1.begin(), nums1.end(),
      nums2.begin(), nums2.end(), std::back_inserter(result));
    
    return result;
  }

  void makeSet(const vector<int> &  v, unordered_multiset<int> & s) const {
    for (const auto & i : v) {
      s.insert(i);
    }
  }
  void makeVector(const unordered_multiset<int>& s, vector<int>& v) const {
    for (const auto& i : v) {
      v.push_back(i);
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

  // Generate test input
  vector<int> v1;// = { 4, 9, 5 };
  vector<int> v2;// = { 9, 4, 9, 8, 4 };
  for (int i = 0; i < 1000; i++)
  {
    v1.push_back(GetRandomNumber(1, 10));
  }
  for (int i = 0; i < 10000000; i++)
  {
    v2.push_back(GetRandomNumber(5, 15));
  }

  Solution s;
  auto res = s.intersect(v1, v2);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << "[ ";
  for (auto r : res)
  {
    cout << r << ",";
  }
  cout << "]" << endl;

  return 0;
};

