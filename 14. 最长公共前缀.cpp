/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res;
        if (strs.size() == 0) {
            return res;
        }
        res = subhead(strs, 0, strs.size() - 1);
        return res;
    }

    string subhead(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }
        if (l == r - 1) {
            string tmp;
            int i = 0;
            while (i < strs[l].size() && i < strs[r].size() && strs[l][i] == strs[r][i]) {
                tmp.push_back(strs[l][i]);
                ++i;
            }
            return tmp;
        }
        string s1 = subhead(strs, l, (l + r) / 2);
        string s2 = subhead(strs, (l + r) / 2 + 1, r);
        string tmp;
        int i = 0;
        while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
            tmp.push_back(s1[i]);
            ++i;
        }
        return tmp;
    }
};