/*
 * @Author: your name
 * @Date: 2020-08-24 17:50:55
 * @LastEditTime: 2020-08-24 17:51:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\459.cpp
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};