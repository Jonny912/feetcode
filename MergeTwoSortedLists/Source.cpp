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

static void printList(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
}

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Solution #1 "Interational method" - T = O(n), S = O(1)
    //ListNode dummy;
    //auto tail = &dummy;
    //while (l1 && l2) {
    //  if (l1->val < l2->val) {
    //    tail->next = l1;
    //    l1 = l1->next;
    //  }
    //  else {
    //    tail->next = l2;
    //    l2 = l2->next;
    //  }
    //  tail = tail->next;
    //}
    //
    //if (l1) {
    //  tail->next = l1;
    //}
    //else if (l2) {
    //  tail->next = l2;
    //}
    //
    //return dummy.next;

    // Solution #2 "Recursive method" - T = O(n), S = O(n)
    cout << "mergeTwoLists() [ ";
    printList(l1); cout << " ] [";
    printList(l2); cout << " ]" << endl;

    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    ListNode* mergedHead = nullptr;

    if (l1->val <= l2->val) {
      mergedHead = l1;
      mergedHead->next = mergeTwoLists(l1->next, l2);
    }
    else {
      mergedHead = l2;
      mergedHead->next = mergeTwoLists(l1, l2->next);
    }
    return mergedHead;
  }
};

static int GetRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

static ListNode* CreateRandomSortedLinkedList(int n) {
  ListNode* head = new ListNode(0);
  auto cur = head;
  for (int i = 0; i < n; i++) {
    auto newNode = new ListNode(GetRandomNumber(i + 1, i + 2));
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
  //auto list1 = CreateRandomSortedLinkedList(6);
  //auto list2 = CreateRandomSortedLinkedList(7);
  auto list1 = CreateList({ 0, 1, 1, 2, 3, 4 });
  auto list2 = CreateList({ 1, 2, 3, 3 });
  printList(list1); cout << endl;
  printList(list2); cout << endl;

  start = clock();
  Solution s;
  auto r = s.mergeTwoLists(list1, list2);
  end = clock();

  printList(r);
  deleteList(r);

  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed
    << time_taken << setprecision(5);
  cout << " sec " << endl;
  return 0;
};
