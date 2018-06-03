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

		for (curr = head, int i = 0; i < (size - n - 1); i++, curr=curr->next);

		curr->next = curr->next->next;

		return head;
    }
};

int main()
{
	return 0;
}
