#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if (root == nullptr) {
            return 0;
        }
        q.push(root);
        int level = 0;
        
        while(!q.empty()) {
            level++;
            
            for (int i = 0, n = q.size(); i < n; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left != nullptr) {
                    q.push(p->left);
                }
                if (p->right != nullptr) {
                    q.push(p->right);
                }
            }
        }
        
        return level;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
		return (root == nullptr) ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
	return 0;
}
