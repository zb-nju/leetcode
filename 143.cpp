/*
 * @Author: zb-nju
 * @Date: 2020-10-20 09:43:10
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-20 10:19:55
 */
#include<iostream>
#include<stack>
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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode*p = head,*fast = head,*slow=head;
        bool flag=false;
        while(fast){
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                flag=true;
            slow=slow->next;
        }
        while(slow){
            s.push(slow);
            slow = slow->next;
        }
        ListNode*l=head,*r=s.top(),*t;
        while(!s.empty()){
            r=s.top();
            t=l->next;
            l->next=r;
            r->next=t;
            l=t;
            s.pop();
        }
        if(flag)
            l->
    }
};