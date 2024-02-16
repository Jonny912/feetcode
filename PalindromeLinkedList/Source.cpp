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
#include <deque>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static void printList(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
}

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    // Solution #1 "Vector analyze" => Time complexity: O(n), Space complexity: O(n)
    //vector<int> v;
    //while (head) {
    //  v.push_back(head->val);
    //  head = head->next;
    //}
    //auto N = v.size();
    //auto M = N / 2;
    //for (int i = 0; i < M; i++) {
    //  if (v[i] != v[N - 1 - i]) {
    //    return false;
    //  }
    //}
    //return true;
    //Solution #2 "Stack" => Time complexity: O(2n), Space complexity: O(n)
    //auto p = head;
    //deque<int> d;
    //while (p) {
    //  d.push_back(p->val);
    //  p = p->next;
    //}
    //while (head) {
    //  if (d.back() != head->val) {
    //    return false;
    //  }
    //  d.pop_back();
    //  head = head->next;
    //}
    //return true;
    // Solution #3 "Reverse second half of the list" => Time complexity: O(1.5*n), Space complexity: O(1)
    // Find a middle of the list
    auto fast = head;
    auto slow = head;
    while (fast) {
      fast = fast->next;
      if (!fast) {
        break;
      }
      else {
        fast = fast->next;
        slow = slow->next;
      }
    }
    // Reverse second half of the list
    ListNode* prev = nullptr;
    while (slow) {
      auto next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    // Check list halfs for identity
    while (prev && head) {
      if (prev->val != head->val) {
        return false;
      }
      prev = prev->next;
      head = head->next;
    }
    return true;
  }
};

static int GetRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

static ListNode* CreateLinkedList(int n) {
  ListNode* head = new ListNode(GetRandomNumber(0, 9));
  auto cur = head;
  for (int i = 0; i < n; i++) {
    auto newNode = new ListNode(GetRandomNumber(0, 9));
    cur->next = newNode;
    cur = cur->next;
  }
  return head;
}

static void deleteList(ListNode* head) {
  while (head) {
    auto next = head->next;
    delete head;
    head = next;
  }
}

static ListNode* CreateList(vector<int> v) {
  ListNode* head = new ListNode(v[0]);
  ListNode* node = head;
  for (int i = 1; i < v.size(); i++) {
    node->next = new ListNode(v[i]);
    node = node->next;
  }
  return head;
}

int main()
{
  srand(static_cast<unsigned int>(time(nullptr)));
  clock_t start, end;
  //auto list1 = CreateLinkedList(100000);
  auto list1 = CreateList({ 1, 2, 3, 3, 2, 1});
  //printList(list1); cout << endl;

  start = clock();
  Solution s;
  auto r = s.isPalindrome(list1);
  end = clock();

  deleteList(list1);

  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;
  cout << r << endl;
  return 0;
};
