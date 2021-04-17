#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        ans = 0; mm = m; nn = n; kk = k;
        vector<vector<bool>>visit(m, vector<bool>(n,false));
        func(visit, 0, 0);
        return ans;
    }

private:
    int ans;
    int mm;
    int nn;
    int kk;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    void func(vector<vector<bool>> &visit, int i, int j){
        if(i < 0 || i >= mm || j < 0 || j >= nn || visit[i][j])
            return;
        int temp = i % 10 + i % 100 / 10 + i / 100 + j % 10 + j % 100 / 10 + j / 100;
        if(temp > kk)
            return;
        ans++;
        visit[i][j] = true;
        for(int x = 0; x < 4; x++)
            func(visit, i + di[x], j+dj[x]);
        return;
    }
};

class Solution {
public:
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    int movingCount(int m, int n, int k) {
        int ans = 0, i, j, ti, tj, t;
        queue<pair<int, int>> q;
        vector<vector<bool>>visit(m, vector<bool>(n,false));
        q.emplace(0, 0);
        visit[0][0] = true;
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            ans++;
            for(int x = 0; x < 4; x++){
                ti = i + di[x];
                tj = j + dj[x];
                if(ti >= 0 && ti < m && tj >= 0 && tj < n && !visit[ti][tj]){
                    t = ti % 10 + ti % 100 / 10 + ti / 100 + tj % 10 + tj % 100 / 10 + tj / 100;
                    if(t <= k){
                        q.emplace(ti, tj);
                        visit[ti][tj] = true;
                    }
                }
            }
        }
        return ans;
    }
};