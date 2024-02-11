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
  // Part of code for Solution #2
  //ListNode* oldHead_;
  //Solution():oldHead_(nullptr) {

  //}

  ListNode* reverseList(ListNode* head) {
    // Solution #1 "Iteratively" => Time: O(n), Space complexity: O(1)
    //auto cur = head;
    //ListNode* prev = nullptr;
    //while (cur) {
    //  auto next = cur->next;
    //  cur->next = prev;
    //  prev = cur;
    //  cur = next;
    //}
    //return prev;

    // Solution #2 "Recursively with member" => Time: O(n), Space: O(n)
    // forward direction semi-iteration algorythm
    //if (head) {
    //  ListNode* next = head->next;
    //  head->next = oldHead_;
    //  oldHead_ = head;
    //  head = next;
    //  return reverseList(head);
    //}
    //return oldHead_;

    // Solution #3 "Recursively without member" => T: O(n), S: O(n)
    // downward direction - true-iteration algorythm
    // tail recursion

    if (!head || !head->next) {
      return head;
    }
    auto newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
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
  srand(static_cast<unsigned int>(time(nullptr)));
  clock_t start, end;

  ListNode* head = new ListNode(1);
  auto cur = head;
  for (int i = 2; i <= 5; i++) {
    cur->next = new ListNode(i);
    cur = cur->next;
  }

  printList(head);

  start = clock();
  Solution s;
  head = s.reverseList(head);
  end = clock();

  printList(head);

  while (head) {
    auto tmp = head;
    head = head->next;
    delete tmp;
  }

  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;

  return 0;
};
