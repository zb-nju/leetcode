/*
 * @Author: your name
 * @Date: 2020-09-05 15:10:27
 * @LastEditTime: 2020-09-07 08:20:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\60.cpp
 */
/*
 * @Author: your name
 * @Date: 2020-09-05 15:10:27
 * @LastEditTime: 2020-09-05 16:19:38
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\60.cpp
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool>use(n, false);
		string ans = "";
		int j, p, f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;
		for (int i = 0; i < n; i++) {
			p = 0;
			f /= (n - i);
			j = (k - 1) / f;
			k -= j * f;
			while (j > 0) {
				if (!use[p])
					j--;
				p++;
			}

			while (use[p])
				p++;
			ans += p + '1';
			use[p] = true;
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.getPermutation(3, 2);
	return 0;
}