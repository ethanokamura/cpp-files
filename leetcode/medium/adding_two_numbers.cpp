#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int sum = 0;
  ListNode* head = new ListNode(-1);  // dummy value
  ListNode* tail = head;
  do {
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    tail->next = new ListNode(sum % 10);
    tail = tail->next;
    if (sum > 9) sum /= 10;
  } while (l1 || l2 || sum != 0);
  return head->next;
}

int main() {
  ListNode* l1 = new ListNode(9);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(9);
  ListNode* l2 = new ListNode(9);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);
  ListNode* sum_list = addTwoNumbers(l1, l2);
  ListNode* cur = sum_list;
  for (int i = 0; i < 4; i++) {
    std::cout << cur->val;
    cur = cur->next;
  }
  std::cout << '\n';
  return 0;
}
