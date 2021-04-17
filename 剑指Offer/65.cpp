#include<iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        int c = 0, res = 0, ta, tb, t;
        for(int i = 0; i < 32; i++){
            ta = (a >> i) & 1;
            tb = (b >> i) & 1;
            t = ta ^ tb ^ c;
            c = (ta & tb) | (tb & c) | (ta & c);
            res |= t << i;
        }
        return res;
    }
};