#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int process(TreeNode* root, int val)
    {
        if (root == nullptr)
            return 0;

        val = (val << 1) | root->val;
        if (!root->left && !root->right)
            return val;

        return process(root->left, val) + process(root->right, val);

    }

    int sumRootToLeaf(TreeNode* root)
    {
        return process(root, 0);
    }
};