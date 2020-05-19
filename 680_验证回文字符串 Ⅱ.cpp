/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

*/
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size() - 1;
        bool res = true;
        for (int i = 0; i < n; ++i, --n) {
            if (s[i] != s[n]) {
                res = fun(s, i + 1, n) || fun(s, i, n - 1);
                break;
            }
        }
        return res;
    }

    bool fun(string s, int start, int end) {
        bool res = true;
        //cout<<start<<" "<<end<<endl;
        // if (start >= end) {
        //     return true;
        // }
        // if (s[start] != s[end]) {
        //     return false;
        // } else {
        //     return fun(s, start + 1, end -1);
        // }
        while (start < end) {
            if (s[start] != s[end]) {
                res = false;
                break;
            }
            start++;
            end--;
        }
        return res;
    }
};