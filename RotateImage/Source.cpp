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
  void rotate(vector<vector<int>>& mat) {

    //
    // Solution #1 - "Brute force with extra space matrix" => Time O(n), Space: O(n)
    // 
    
    //vector<vector<int>> matrix2(matrix[0].size(), vector<int>(matrix.size()));
   
    //for (int i = 0; i < matrix.size(); i++) {
    //  matrix2[i].resize(matrix[i].size());
    //  for (int j = 0; j < matrix[0].size(); j++) {
    //    matrix2[j][matrix.size() - 1 - i] = matrix[i][j];
    //  }
    //}
    //matrix = move(matrix2);
    // 
    
    //
    // Solution #2 - "Rotate by rows and columns swaping" => Time O(n*n), Space: O(1)
    //
    //auto N = mat.size();
    //for (int x = 0; x < N / 2; x++) {
    //  for (int y = x; y < N - x - 1; y++) {
    //    int D = N - 1;
    //    auto top    = &mat[x][y];
    //    auto right  = &mat[y][D - x];
    //    auto bottom = &mat[D - x][D - y];
    //    auto left   = &mat[D - y][x];
    //    int tmp = *top;
    //    *top = *left;
    //    *left = *bottom;
    //    *bottom = *right;
    //    *right = tmp;
    //  } // for y
    //} // for x

    // 
    // Solution #3 Transpose the matrix & Swap the columns => Time O(n) 
    // 
    auto row = mat.size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j <= i; j++) {
        swap(mat[i][j], mat[j][i]);
      }
    }
    for (int i = 0; i < row; i++) {
      reverse(mat[i].begin(), mat[i].end());
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
  //vector<vector<int>> matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

  vector<vector<int>> m;
  auto N = 1000;
  auto n = 1;
  for (int i = 0; i < N; i++) {
    vector<int> v;
    for (int j = 0; j < N; j++) {
      v.push_back(n++);
    }
    m.push_back(v);
  }

  Solution s;
  s.rotate(m);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  //for (int i = 0; i < m.size(); i++) {
  //  for (int j = 0; j < m.size(); j++) {
  //    cout << m[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  return 0;
};
