#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        ListNode *p1 = l1, *p2 = l2, *head = nullptr, *p3 = nullptr;
        if(p1->val>p2->val){
            head = p3 = p2;
            p2 = p2->next;
        }
        else{
            head = p3 = p1;
            p1 = p1->next;
        }
        while(p1 && p2){
            if(p1->val>p2->val){
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else{
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        if(p1)
            p3->next = p1;
        else
            p3->next = p2;
        return head;
    }
};