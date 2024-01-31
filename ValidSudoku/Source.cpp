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
  unordered_set<char> uniqueLine;

  bool isDigit(char ch) {
    return (ch >= 49 && ch <= 57);
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    // check lines
    for (vector<char> & line : board) {
      uniqueLine.clear();
      for (auto ch : line) {
        // check for empty
        if (ch == '.') continue;
        // check for digits 1-9
        if (!isDigit(ch)) return false;
        // chek for duplicates
        auto res = uniqueLine.insert(ch);
        if (res.second != true) {
          return false;
        }
        else {
          continue;
        }
        return false;
      }
    }

    // check columns
    for (int j = 0; j <= 8; j++) {
      uniqueLine.clear();
      for (int i = 0; i <= 8; i++) {
        auto ch = board[i][j];
        // check for empty
        if (ch == '.') continue;
        // check for digits 1-9
        if (!isDigit(ch)) return false;
        // chek for duplicates
        auto res = uniqueLine.insert(ch);
        if (res.second != true) {
          return false;
        }
        else {
          continue;
        }
        return false;
      }
    }

    // check quads 3x3
    for (int squadLineIndex = 0; squadLineIndex <= 2; squadLineIndex++) {
      for (int squadColIndex = 0; squadColIndex <= 2; squadColIndex++) {
        uniqueLine.clear();
        if (!isSquadValid(squadLineIndex, squadColIndex, board)) {
          return false;
        }
      }
    }
    return true;
  }

  bool isSquadValid(int squadLineIndex, int squadColIndex, vector<vector<char>> & board) {
    for (int i = squadLineIndex * 3; i <= 2 + squadLineIndex * 3; i++) {
      for (int j = squadColIndex * 3; j <= 2 + squadColIndex * 3; j++) {
        auto ch = board[i][j];
        // check for empty
        if (ch == '.') continue;
        // check for digits 1-9
        if (!isDigit(ch)) return false;
        // chek for duplicates
        auto res = uniqueLine.insert(ch);
        if (res.second != true) {
          return false;
        }
        else {
          continue;
        }
        return false;
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

  // Make test input
  vector<vector<char>> board =  {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
  Solution s;
  auto res = s.isValidSudoku(board);
  for (int i = 0; i < 100; i++)
    s.isValidSudoku(board);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  cout << (res ? "true " : "false" ) << endl;

  return 0;
};
