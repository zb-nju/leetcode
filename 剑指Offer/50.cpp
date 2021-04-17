#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> mymap;
        for(auto &c:s)
            mymap[c]++;
        for(auto &c:s)
            if(mymap[c] == 1)
                return c;
        return ' ';
    }
};