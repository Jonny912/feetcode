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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // My own solution #1 => Time = O(n)
    //vector<ListNode*> v;
    //auto cur = head;
    //while (cur) {
    //  v.push_back(cur);
    //  cur = cur->next;
    //}
    //auto p = v[v.size() - n];
    //if (v.size() == 1) return NULL;
    //if (p->next) {
    //  *p = *p->next; // crop list
    //}
    //else {
    //  v[v.size() - n - 1]->next = NULL; // n == 1, remove last element
    //}
    //return head;

    // Solution #2 "Fast & Slow pointers" => Time = O(n), Space = O(1)
    if (!head->next) return NULL;
    auto fast = head, slow = head;
    for (int i = 0; fast != NULL; i++) {
      fast = fast->next;
      if (i >= n && slow->next) {
        if (!fast && n == 1) {
          delete slow->next;
          slow->next = NULL;
          break;
        }
        slow = slow->next;
      }
    }
    if (slow && slow->next) {
      auto r = slow->next;
      *slow = *slow->next;

      delete r;
    }

    return head;
  }
};

void printList(ListNode* head) {
  auto p = head;
  cout << "[ ";
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "]";
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
  //ListNode* head = new ListNode(1, new ListNode(2));
 // ListNode* head = new ListNode(1);

  ListNode* head(new ListNode(1));
  auto cur = head;
  for (unsigned i = 2; i <= 5; i++) {
    cur->next = new ListNode(i);
    cur = cur->next;
  }

  printList(head);

  /* Recording the starting clock tick.*/
  start = clock();

  Solution s;
  printList(s.removeNthFromEnd(head, 5));

  // Recording the end clock tick.
  end = clock();

  // Calculating total time taken by the program.
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;


  return 0;
};
