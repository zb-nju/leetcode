#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    inline long long get(int & bit,long long & j) { //获得j进制下，bit 位全是1的数 
        long long res=0;
        long long max = LLONG_MAX / j;
        for(int i = 0; i < bit; ++i){
            res = res * j + 1;
            if(res > max && i < bit - 1)
                return -1;
        }
        return res;
    }

    string smallestGoodBase(string n) {
        long long num = stol(n);
        long long res = num - 1; //结果

        long long globalRight = num - 1; //全局二分进制范围
        int i = 2; //当前在r位1下找进制

        long long left;//当前二分范围
        long long right;
        long long mid;
        long long tmp;
        while(2<=globalRight) {
            left = 2;
            right = globalRight;
            ++i;
            while(left<=right) {
                mid = (left+right)/2;

                tmp = get(i, mid);

                if(tmp == num) {
                    res = mid;
                    right = mid;
                    break;
                }else if(tmp > num||tmp < 0) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }
            globalRight = right;
        }

        return to_string(res);

    }
};