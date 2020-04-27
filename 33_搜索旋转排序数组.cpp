/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (nums[0] > target && nums[n - 1] <target) {
            return -1;
        }
        return localTarget(nums, 0, n -1, target);
    }

    int localTarget(vector<int>& nums, int l, int r, int target) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (l >= r) {
            return -1;
        }
        
        if (nums[l] <= target && nums[mid] > target) {
            return localTarget(nums, l, mid - 1, target);
        } else if (nums[l] <= target && nums[mid] < target && nums[l] < nums[mid]) {
            return localTarget(nums, mid + 1, r, target);
        } else if (nums[l] <= target && nums[mid] < target && nums[l] > nums[mid]) {
            return localTarget(nums, l, mid - 1, target);
        } else if (nums[r] >= target && nums[mid] < target) {
            return localTarget(nums, mid + 1, r, target);
        } else if (nums[r] >= target && nums[mid] > target && nums[r] > nums[mid]) {
            return localTarget(nums, l, mid - 1, target);
        } else if (nums[r] >= target && nums[mid] > target && nums[r] < nums[mid]) {
            return localTarget(nums, mid + 1, r, target);
        }
        return -1;
    }
};