#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* headless = new ListNode(0);
		ListNode* headmore = new ListNode(0);
		ListNode* less = headless;
		ListNode* more = headmore;
		ListNode* p = head;
		while (p) {
			if (p->val < x) {
				less->next = p;
				less = less->next;
			}
			else {
				more->next = p;
				more = more->next;
			}
			p = p->next;
		}
		less->next = headmore->next;
		more->next = NULL;
		return headless->next;
	}
};