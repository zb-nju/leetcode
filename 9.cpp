#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int t1=x,t2=0;
        while(t1)
        {
            t2=t2*10+t1%10;
            t1/=10;
        }
        return t2==x;
    }
};