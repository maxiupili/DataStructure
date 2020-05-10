/**
236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

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
    unordered_map<int,int> mymap;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root);
        vector<int> vp;
        vector<int> vq;
        int tmpp = p->val;
        int tmpq = q->val;
        vp.push_back(p->val);
        vq.push_back(q->val);
        while (mymap.find(tmpp) != mymap.end()) {
            vp.push_back(mymap.at(tmpp));
            tmpp = mymap.at(tmpp);
        }
        while (mymap.find(tmpq) != mymap.end()) {
            vq.push_back(mymap.at(tmpq));
            tmpq = mymap.at(tmpq);
        }
        int res = root->val;
        int i = vp.size() - 1;
        int j = vq.size() - 1;
        while (i >= 0 && j >= 0 && vp[i] == vq[j]) {
            res = vp[i];
            --i;
            --j;
        }
        TreeNode *ans = new TreeNode(res);
        return ans;
    }

    void travel(TreeNode* root)
    {
        if (root->left != NULL) {
            mymap[root->left->val] = root->val;
            travel(root->left);
        }
        if (root->right != NULL) {
            mymap[root->right->val] = root->val;
            travel(root->right); 
        }
        return;
    }
};