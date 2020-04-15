/*
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    struct site
    {
        int x, y;
    };
    vector<vector<int>> move = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
    //int visit[1000][1000] = {0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //cout<<row<<col;
        vector<vector<int>> res;
        for (int i = 0; i < row; i++) {
            vector<int> vi;
            for (int j = 0; j < col; j++) {
                //cout<<i<<j<<endl;
                vi.push_back(BFS(matrix, i, j));
                //memset(visit, 0, 1000000);
            }
            
            res.push_back(vi);
            
        }
//         cout<<BFS(matrix, 0, 0)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 0, 1)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 0, 2)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 1, 0)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 1, 1)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 1, 2)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 2, 0)<<endl;
// memset(visit, 0, 10000);        
//         cout<<BFS(matrix, 2, 1)<<endl;
// memset(visit, 0, 10000);
//         cout<<BFS(matrix, 2, 2)<<endl;
        
        return res;
    }

    int BFS(vector<vector<int>>& matrix, int i, int j)
    {
        site tmpSite;
        tmpSite.x = i;
        tmpSite.y = j;
        queue<site> que;
        que.push(tmpSite);
        while (!que.empty()) {
            int x = que.front().x;
            int y = que.front().y;
            que.pop();
            //visit[x][y] = 1;
            if (matrix[x][y] == 0)
            {
                //cout<<x<<y<<endl;
                return abs(x - i) + abs(y - j);
            } else {
                for (int loop = 0; loop < 4; ++loop) {
                    site tmpSite2;
                    tmpSite2.x = x + move[loop][0];
                    tmpSite2.y = y + move[loop][1];
                    if (IsValid(matrix, tmpSite2.x, tmpSite2.y) ) {  //&& visit[tmpSite2.x][tmpSite2.y] == 0
                        que.push(tmpSite2);
                        //visit[tmpSite2.x][tmpSite2.y] = 1;
                    }
                }
            }
            
        }
        return 0;
    }

    bool IsValid(vector<vector<int>>& matrix, int i, int j)
    {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return false;
        }
        return true;
    }
};