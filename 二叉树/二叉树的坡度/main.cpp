class Solution {
public:
#define absolute(a) ((a) > 0 ? (a) : (-(a)));
    int process(TreeNode* root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->val;

        int left = process(root->left);
        int right = process(root->right);
        _sum += absolute(left - right);


        return left + right + root->val;
    }

    int findTilt(TreeNode* root)
    {
        process(root);
        return _sum;
    }

private:
    int _sum = 0;
};