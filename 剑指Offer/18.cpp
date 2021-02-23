/*
 * @Author: your name
 * @Date: 2020-07-11 23:14:15
 * @LastEditTime: 2020-07-11 23:27:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\剑指Offer\18.cpp
 */ 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        ListNode*pre=head,*p=head;
        while(p!=nullptr&&p->val!=val){
            pre=p;
            p=p->next;
        }
        if(p==head)
            return head->next;
        if(p)
            pre->next=p->next;
        return head;
    }
};