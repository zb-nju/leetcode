#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int i = 0, l = 0, r;
        while(i < n){
            if(s[i] != ' '){
                if(l != 0)
                    s[l++] = ' ';
                r = l;
                while(i < n && s[i] != ' '){
                    s[r] = s[i];
                    r++;
                    i++;
                }
                reverse(s.begin() + l, s.begin()　+ r);
                l = r;
            }
            else
                i++;
        }
        s.erase(s.begin() + l, s.end());
        return s;
    }
};