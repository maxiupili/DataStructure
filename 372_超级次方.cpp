// 你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

// 示例 1:

// 输入: a = 2, b = [3]
// 输出: 8
// 示例 2:

// 输入: a = 2, b = [1,0]
// 输出: 1024

// (a * b) % p = (a % p * b % p) % p
// 先写一个求次方的函数。
// 由于次方b给的是数组，直接转为数字求次方也会导致溢出，所有转为每个位上的次方，下一轮开始的时候求个10次方。

class Solution {
public:
	int qpow(int a, int b, int m)
	{
		int res = 1;
		while (b)
		{
            //cout<<(b & 1)<<endl;
			if (b & 1) {
                res = (res * a) % m;
            }
			a = (a % m) * (a % m) % m;
			b >>= 1;
            //cout<<"b "<<b<<endl;
		}
		//上面的while与下面结果一致，利用对指数右移（除2）并对右移后的指数进行奇偶判断，以a的2次方为递乘单元，降低时间复杂度
        // while (b--) {
        //     res = (res * (a % m)) % m;
        // }
		return res;
	}
	int superPow(int a, vector<int>& b) {
		int n = 0, res = 1;
		for (int x : b) {
            res = qpow(res,10,1337) * qpow(a, x, 1337) % 1337;
        }
		return res;
	}
};


