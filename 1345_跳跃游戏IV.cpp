/*

1345. 跳跃游戏 IV
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。

 

示例 1：

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
示例 2：

输入：arr = [7]
输出：0
解释：一开始就在最后一个元素处，所以你不需要跳跃。
示例 3：

输入：arr = [7,6,9,6,9,6,9,7]
输出：1
解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
示例 4：

输入：arr = [6,1,9]
输出：2
示例 5：

输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
输出：3
 
*/
class Solution {
public:
	Solution() {}
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, vector<unsigned short> > mp;
        //存储值为int的所有数组下标vector<unsigned short>，选择unsignedshort是因为下标范围是0到50000
		for (int i = 0; i < n; ++i) {
			mp[arr[i]].push_back(i); //记录相同值的下标集合
		}
		unordered_map<int, bool> searched; //看某个值有没有被搜索过,而不是看坐标
		queue<int> que;
		que.push(0);
		int step = 0;
		/*广度优先遍历*/
		while (!que.empty()) {
			int cursize = que.size();
			for (int i = 0; i < cursize; ++i) {
				int tmp = que.front();//出队
				que.pop();
				
				if (tmp == n - 1) return step;
				//可达点分为三种情况
				/*左邻居*/
				if (tmp - 1 >= 0 && searched[arr[tmp - 1]] == false) {
					que.push(tmp - 1);
				}
				/*右邻居*/
				if (tmp + 1 < n && searched[arr[tmp + 1]] == false) {
					que.push(tmp + 1);
				}
				/*同值可达点*/
				if (searched[arr[tmp]] == false) {
					vector<unsigned short>* tmp_pointer = &mp[arr[tmp]]; //记下指针有利于提高速度，不然每次下标访问都要查找
					for (int j = 0; j < tmp_pointer->size(); ++j) {
						if ((*tmp_pointer)[j] != tmp - 1 && (*tmp_pointer)[j] != tmp + 1) {
							que.push((*tmp_pointer)[j]);
						}
					}
					searched[arr[tmp]] = true;//访问该点，意味着所有同值可达点均被访问过，不会有第二次找同值可达点的机会
				}
			}
			++step;
		}
		return step;
	}
};
