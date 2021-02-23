#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // int ans=m;
        // for(int i=m+1;i<=n;i++)
        //     ans&=i;
        // return ans;

        int t=0;
        while(m<n){
            m>>=1;
            n>>=1;
            t++;
        }
        return n<<t;
    }
};