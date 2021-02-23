/*
 * @Author: your name
 * @Date: 2020-08-10 23:04:11
 * @LastEditTime: 2020-08-10 23:12:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\剑指Offer\22.cpp
 */
#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* f=head,*s=head;
        for(int i=0;i<k;i++){
            s=s->next;
        while(s){
            s=s->next;
            f=f->next;
        }
        return f;
    }
};