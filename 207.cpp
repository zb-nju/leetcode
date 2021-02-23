/*
 * @Author: your name
 * @Date: 2020-08-04 10:24:08
 * @LastEditTime: 2020-08-05 00:03:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\207.cpp
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
// 		vector<int> indegree(numCourses, 0);
// 		for (int i = 0; i < prerequisites.size(); i++)
// 			indegree[prerequisites[i][0]]++;
// 		int t,ans=0;
// 		while (1) {
// 			t = numCourses;
// 			for (int i = 0; i < numCourses; i++) {
// 				if (indegree[i] == 0) {
// 					t = i;
// 					indegree[i] = -1;
// 					ans++;
// 					break;
// 				}
// 			}
// 			if (ans == numCourses)
// 				return true;
// 			if (t == numCourses)
// 				return false;
// 			for (int i = prerequisites.size() - 1; i >= 0; i--)
// 				if (prerequisites[i][1] == t){
// 					indegree[prerequisites[i][0]]--;
//                     prerequisites.erase(prerequisites.begin()+i);
//                 }
// 		}
// 		return true;
//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size(), t, ans = 0;
		if (!n)
			return true;
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> G(numCourses);
		queue<int>q;
		for (int i = 0; i < n; i++) {
			indegree[prerequisites[i][0]]++;
			G[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		for (int i = 0; i < numCourses; i++)
			if (!indegree[i]) {
				q.push(i);
				ans++;
			}
		while (!q.empty()) {
			t = q.front();
			q.pop();
			for (int i = 0; i < G[t].size(); i++) {
				int j = G[t][i];
				if (!--indegree[j]) {
					q.push(j);
					ans++;
				}
			}
		}
		return ans == numCourses;
    }
};