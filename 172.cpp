#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0, five = 0;
        for(int i = 2; i <= n; i*=2)
            two += n/i;
        for(int i = 5; i <= n; i*=5)
            five += n/i;
        return min(two, five);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        for(int i = 5; i <= n; i*=5)
            five += n/i;
        return five;
    }
};