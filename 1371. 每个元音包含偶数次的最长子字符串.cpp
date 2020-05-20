/*
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

 

示例 1：

输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2：

输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
示例 3：

输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。

遍历s 得出每个下标位置的前缀中aeiou的奇偶状态，并且在记录个状态最早出现的下标，得出最大值
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> status(32, -1);
        int max = 0;
        int flag = 0;
        status[0] = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                flag ^= (1 << 4);
            } else if (s[i] == 'e') {
                flag ^= (1 << 3);
            } else if (s[i] == 'i') {
                flag ^= (1 << 2);
            } else if (s[i] == 'o') {
                flag ^= (1 << 1);
            } else if (s[i] == 'u') {
                flag ^= 1;
            }
            if (status[flag] == -1) {
                status[flag] = i + 1;
            } else {
                if (max < i + 1 - status[flag]) {
                    max = i + 1 - status[flag];
                }
            }
        }
        return max;
    }
};