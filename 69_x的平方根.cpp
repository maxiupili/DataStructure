/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int mySqrt(int x) {
        int mid = x / 2;
        int l = 0;
        int r = x;
        
        while (true) {
            if ((long long) mid * mid <= x && (long long) (mid + 1) * (mid + 1) > x) {
                return mid;
            }
            if ((long long) mid * mid > x) {
                r = mid - 1;
                mid = l + (mid - l) / 2;
            } else if ((long long) (mid + 1) * (mid + 1) <= x) {
                l = mid + 1;
                mid = l + (r - mid) / 2;
            }
        }
    }
};
// class Solution {
// public:
//     int mySqrt(int x) {
//         int l = 0, r = x, ans = -1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if ((long long)mid * mid <= x) {
//                 ans = mid;
//                 l = mid + 1;
//             }
//             else {
//                 r = mid - 1;
//             }
//         }
//         return ans;
//     }
// };
