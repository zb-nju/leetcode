/*
 * @Author: zb-nju
 * @Date: 2020-10-13 15:46:48
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-14 10:13:59
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        
        ListNode*first = head,*second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};