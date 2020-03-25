class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    continue;
                } else {
                    sum += 2;
                    if (i - 1 < 0) {
                        sum += grid[i][j];
                    } else {
                        sum += (((grid[i][j] - grid[i - 1][j]) < 0) ? 0: (grid[i][j] - grid[i - 1][j]));
                    }

                    if (j - 1 < 0) {
                        sum += grid[i][j];
                    } else {
                        sum += (((grid[i][j] - grid[i][j - 1]) < 0) ? 0: (grid[i][j] - grid[i][j - 1]));
                    }

                    if (i + 1 >= row) {
                        sum += grid[i][j];
                    } else {
                        sum += (((grid[i][j] - grid[i + 1][j]) < 0) ? 0: (grid[i][j] - grid[i + 1][j]));
                    }

                    if (j + 1 >= col) {
                        sum += grid[i][j];
                    } else {
                        sum += (((grid[i][j] - grid[i][j + 1]) < 0) ? 0: (grid[i][j] - grid[i][j + 1]));
                    }
                }
            }
        }
        return sum;
    }
};
// 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

// 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

// 请你返回最终形体的表面积。

//  对每一个点的立柱：上下提供表面积，前后左右具体与相邻柱体分析

// 示例 1：

// 输入：[[2]]
// 输出：10
// 示例 2：

// 输入：[[1,2],[3,4]]
// 输出：34
// 示例 3：

// 输入：[[1,0],[0,2]]
// 输出：16
// 示例 4：

// 输入：[[1,1,1],[1,0,1],[1,1,1]]
// 输出：32
// 示例 5：

// 输入：[[2,2,2],[2,1,2],[2,2,2]]
// 输出：46
//  

// 提示：

// 1 <= N <= 50
// 0 <= grid[i][j] <= 50
