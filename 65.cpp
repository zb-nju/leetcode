#include<iostream>
#include<regex>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        regex rx("\\s*[+-]?(((\\d+)(\\.\\d*)?)|(\\.\\d+))([Ee][+-]?\\d+)?\\s*");
        return regex_match(s, rx);
    }
};