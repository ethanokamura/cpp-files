#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int x = 0;
  int digit = 1;
  while (l1 != nullptr) {
    std::cout << "l1\n";
    x += l1->val * digit;
    digit *= 10;
    l1 = l1->next;
  }
  std::cout << x << '\n';
  int y = 0;
  digit = 1;
  while (l2->next != nullptr) {
    std::cout << "l2\n";
    y += l2->val * digit;
    digit *= 10;
    l2 = l2->next;
  }
  std::cout << y << '\n';
  x += y;
  ListNode* l;
  while (x > 0) {
    ListNode temp(x % 10);
    x /= 10;
    l = &temp;
    l = l->next;
  }
  return l;
}

int main() { return 0; }