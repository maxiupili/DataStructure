/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                //由前i - 1长度的word1转化为 前j长度的word2需要D[i - 1][j]步编辑
                //因此i长度的word1转化为前j长度的word2需要D[i - 1][j] + 1步编辑
                int left = D[i - 1][j] + 1; 
                //由前i长度的word1转化为前j-1长度的word2需要D[i][j - 1]步编辑
                //因此i长度的word1转化为前j长度的word2需要D[i][j - 1] + 1步编辑
                int down = D[i][j - 1] + 1;
                //由前i - 1长度的word1转化为 前j - 1长度的word2需要D[i - 1][j - 1]步编辑
                //因此i长度的word1转化为前j长度的word2需要D[i - 1][j - 1]或D[i - 1][j - 1] + 1步编辑，取决于尾字母是否相等
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                //D[i][j]取三者中小的
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};
