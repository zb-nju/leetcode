#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        vector<int> f(n+1, 0);
        f[0]=f[1]=1;
        for(int i = 2;i <= n; i++)
            f[i] = (f[i-1] + f[i-2]) % int(1e9+7);
        return f[n];
    }
};