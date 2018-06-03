#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool is_bst = true;
        if (root == nullptr) {
            return is_bst;
        }
        if (root->left != nullptr) {
            TreeNode *left = root->left;
            while(left->right != nullptr) {
                left = left->right;
            }
            if (left->val >= root->val) {
                is_bst = false;
            }
        }
        if (root->right != nullptr) {
            TreeNode *right = root->right;
            while(right->left != nullptr) {
                right = right->left;
            }
            if (right->val <= root->val) {
                is_bst = false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right) && is_bst;
    }
};

int main()
{
	return 0;
}
