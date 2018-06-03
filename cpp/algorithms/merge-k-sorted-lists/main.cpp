#include <iostream>
#include <string>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head = nullptr;
		ListNode *curr = nullptr;

		while (true) {
			ListNode *tmp = nullptr;
			int min_list = 0;

			for (int i = 0; i < lists.size(); ++i) {
				if (lists[i] != nullptr) {
					if (tmp == nullptr) {
						tmp = lists[i];
						min_list = i;
					} else {
						if (lists[i]->val < tmp->val) {
							tmp = lists[i];
							min_list = i;
						}
					}
				}
			}

			if (tmp == nullptr) {
				break;
			}

			lists[min_list] = lists[min_list]->next;

			if (head == nullptr) {
				head = tmp;
				curr = tmp;
			} else {
				curr->next = tmp;
				curr=curr->next;
			}
		}

		return head;
    };
};

int main()
{
	return 0;
}
