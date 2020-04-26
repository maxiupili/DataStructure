/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        vector<bool> used(n, false);
        vector<int> path;
        
        dfs(res, nums, path, used, 0, n);
        
        return res;
    }
    
    void dfs(vector<vector<int> >& res, vector<int>& nums, vector<int>& path, vector<bool> used, int depth, int n) {
        if (depth == n) {
            res.push_back(path);
            return ;
        }
        
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            };
            path.push_back(nums[i]);
            used[i] = true;
            dfs(res, nums, path, used, depth + 1, n);
            path.pop_back();
            used[i] = false;
        }
        
    }
};
