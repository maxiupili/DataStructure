/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

双指针 从数组两端开始小的一端开始向中间移动，遇到比两侧矮的值累加该下标上可积累的雨水
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxleft = 0;
        int maxright = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > maxleft) {
                    maxleft = height[left];
                } else {
                    res += (maxleft - height[left]);
                }
                ++left;
            } else {
                if (height[right] > maxright) {
                    maxright = height[right];
                } else {
                    res += (maxright - height[right]);
                }
                --right;
            }
        }
        return res;
    }
};