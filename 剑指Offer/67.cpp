#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        if(str == "")
            return 0;
        int ans = 0, sign = 1, bndry = 214748364, i = 0, n = str.size();
        while(str[i] == ' ')
            if(++i == n)
                return 0;
        if(str[i] == '-') sign = -1;
        if(str[i] == '+' || str[i] == '-') i++;
        while(i < n && str[i] >= '0' && str[i] <= '9'){
            if(ans > bndry || (ans == bndry && str[i] > '7'))
                return sign > 0 ? 2147483647 : -2147483648;
            ans = ans * 10 + (str[i] - '0');
            i++;
        }
        return ans * sign;
    }
};