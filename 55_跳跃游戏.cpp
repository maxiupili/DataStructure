/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int n = nums.size();
        vector<int> visit(n, 0);
        queue<int> que;
        que.push(n - 1);
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (int i = tmp - 1; i >=0; --i) {
                if (i + nums[i] >= tmp && visit[i] == 0) {
                    if (i == 0) {
                        return true;
                    }
                    visit[i] = 1;
                    que.push(i);
                }
            }
        }
        return false;
    }
};