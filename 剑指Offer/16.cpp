#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0)
            return func(x, n);
        else{
            return 1/func(x, -n);
        }
    }

    double func(double x, long n){
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        else{
            double t = myPow(x, n/2);
            if(n%2==0)
                return t*t;
            else
                return t*t*x;
        }
        return -1;
    }
};