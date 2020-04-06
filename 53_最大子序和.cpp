/*

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            //dp[i]表示的是包含且以nums[i]结尾的子序的最大和
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            //cout<<dp[i]<<endl;
            //最大子序和可能出现在中间
            res = max(res, dp[i]);
        }
        return res;
    }
};