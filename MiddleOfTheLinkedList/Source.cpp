#include <string>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* middleNode(ListNode* head)
  {
    auto fast = head;
    auto slow = head;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
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

  ListNode* head = new ListNode(1);
  auto cur = head;
  for (int i = 2; i <= 5000; i++)
  {
    cur->next = new ListNode(i);
    cur = cur->next;
  }

  auto res = s.middleNode(head);

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  printf("steps amount is = %d\n", res->val);
  while (head)
  {
    auto next = head->next;
    delete head;
    head = next;
  }
  return 0;
};

