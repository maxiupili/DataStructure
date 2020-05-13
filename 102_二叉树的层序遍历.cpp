/**
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> myq;
        if (root == nullptr) {
            return ans;
        }
        myq.push(root);
        while (!myq.empty()) {
            int n = myq.size();
            //int tmpv;
            TreeNode* tmpr;
            vector<int> vc;
            while (n--) {
                tmpr = myq.front();
                myq.pop();
                if (tmpr->left != nullptr) {
                    myq.push(tmpr->left);
                }
                if (tmpr->right != nullptr) {
                    myq.push(tmpr->right);
                }
                vc.push_back(tmpr->val);
            }
            ans.push_back(vc);
        }
        return ans;
    }
};