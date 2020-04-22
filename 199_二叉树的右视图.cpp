/**
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            res.push_back(que.back()->val);
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *tmp = que.front();
                que.pop();
                if (tmp->left != NULL) {
                    que.push(tmp->left);
                }
                if (tmp->right != NULL) {
                    que.push(tmp->right);
                }
            }
        }
        return res;
    }
};