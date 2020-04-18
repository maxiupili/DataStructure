/*
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任意 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

 

示例 1：

输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -> 下标 4 -> 下标 1 -> 下标 3 
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3 
示例 2：

输入：arr = [4,2,3,0,3,1,2], start = 0
输出：true 
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 0 -> 下标 4 -> 下标 1 -> 下标 3
示例 3：

输入：arr = [3,0,2,1,2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。 
 

提示：

1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length

*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }
        int n = arr.size();
        vector<int> visit(n, 0);
        visit[start] = 1;
        vector<int> vc;
        vc.push_back(start);
        while (vc.size() != 0) {
            int tmp = vc.back();
            vc.pop_back();
            if (tmp + arr[tmp] < n && visit[tmp + arr[tmp]] == 0) {
                if (arr[tmp + arr[tmp]] == 0) {
                    return true;
                }
                vc.push_back(tmp + arr[tmp]);
                visit[tmp + arr[tmp]] = 1;
            }
            if (tmp - arr[tmp] >= 0 && visit[tmp - arr[tmp]] == 0) {
                if (arr[tmp - arr[tmp]] == 0) {
                    return true;
                }
                vc.push_back(tmp - arr[tmp]);
                visit[tmp - arr[tmp]] = 1;
            }
        }
        return false;
    }
};