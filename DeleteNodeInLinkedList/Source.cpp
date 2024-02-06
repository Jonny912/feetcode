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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  void deleteNode(ListNode* node) {
    // Solution #1 "loop" (IT IS NOT OPTIMAL): Time = O(n)
    //while (node) {
    //  if (node->next) {
    //    node->val = node->next->val;
    //    if (!node->next->next) {
    //      node->next = NULL;
    //      break;
    //    }
    //    node = node->next;
    //  }
    //}
    // Solution #2 "Cut" (OPTIMAL): Time = O(1)
    *(node) = *(node->next);
  }
};

void printList(ListNode* head) {
  auto p = head;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

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

  // Build test list 
  ListNode* head = new ListNode(0);
  ListNode* node = NULL;
  ListNode* cur = head;
  for (unsigned i = 1; i <= 20; i++) {
    cur->next = new ListNode(i);
    if (i == 5) {
      node = cur;
    }
    cur = cur->next;
  }

  printList(head);

  /* Recording the starting clock tick.*/
  start = clock();

  Solution s;
  s.deleteNode(node);

  // Recording the end clock tick.
  end = clock();

  printList(head);

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;


  return 0;
};
