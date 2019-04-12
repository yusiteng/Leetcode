/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* hh = new ListNode(0);
		ListNode* pre = hh;
		ListNode* p = head;
		while (p){
			if (p->next == NULL || p->next->val != p->val) {
				pre->next = p;
				pre = p;
			}
			int val = p->val;
			while (p && p->val==val){
				p = p->next;
			}
		}
		pre->next = NULL;
		return hh->next;
	}
};