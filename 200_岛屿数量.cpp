/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


*/
class Solution {
public:

    struct site {
        int x;
        int y;
    };

    vector<vector<int>> move = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n));
        vector<site> vc;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && visit[i][j] == 0) {
                    site s1;
                    s1.x = i;
                    s1.y = j;
                    vc.push_back(s1);
                    visit[i][j] = 1;
                    while (vc.size() > 0) {
                        //cout<<vc.size()<<endl;
                        site s2;
                        s2.x = vc.back().x;
                        s2.y = vc.back().y;
                        vc.pop_back();
                        for (int k = 0; k < 4; ++k) {
                            if (isValued(grid, s2.x + move[k][0], s2.y + move[k][1]) && visit[s2.x + move[k][0]][s2.y + move[k][1]] == 0 &&
                            grid[s2.x + move[k][0]][s2.y + move[k][1]] == '1') {
                                site s3;
                                s3.x = s2.x + move[k][0];
                                s3.y = s2.y + move[k][1];
                                vc.push_back(s3);
                                visit[s3.x][s3.y] = 1;
                            }
                        }
                    }
                    ++res;
                }
            }
        }
        // for (auto x : visit) {
        //     for (auto y : x) {
        //         cout<< y << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }

    bool isValued(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return false;
        }
        return true;
    }
};