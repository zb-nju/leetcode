/*
 * @Author: your name
 * @Date: 2020-07-10 17:31:06
 * @LastEditTime: 2020-07-10 17:54:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1175.cpp
 */ 

#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<int> isPrime(n+1,1);
        isPrime[0]=isPrime[1]=0;
        for(int i=0;i<=n;i++){
            if(isPrime[i])
                for(int j=2*i;j<=n;j+=i)
                    isPrime[j]=0;
        }
        int p=accumulate(isPrime.begin(),isPrime.end(),0);
        int notp=n-p,i=1,mod=pow(10,9)+7;
        long long ans=1;
        while(i<=p){
            ans=ans*i%mod;
            i++;
        }
        i=1;
        while(i<=notp){
            ans=ans*i%mod;
            i++;
        }
        return ans;
    }
};


int main()
{
    Solution s;
    cout<<s.numPrimeArrangements(100);
    return 0;
}