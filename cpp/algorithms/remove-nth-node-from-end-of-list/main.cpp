#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *curr = head;
		int size = 0;
		while (curr != nullptr) {
			size++;
			curr = curr->next;
		}

		if (size == n) {
			return head->next;
		}

		int i = 0;
		for (curr = head, i = 0; i < (size - n - 1); i++, curr=curr->next);

		curr->next = curr->next->next;

		return head;
    };
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
		ListNode *curr = head;
		ListNode *p = head;

		for (int i = 0; i < n; curr=curr->next, ++i);

		if (curr == nullptr) {
			return head->next;
		}

		while (curr->next != nullptr) {
			p = p->next;
			curr = curr->next;
		}

		p->next = p->next->next;
		return head;
    };
};

int main()
{
	return 0;
}
