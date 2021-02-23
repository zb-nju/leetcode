#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* newNode=new ListNode(0);
        ListNode* p=head,*pre=head;
        while(p){
            if(p->next==newNode)
                return true;
            pre = p;
            p=p->next;
            pre->next = newNode;
        }
        return false;
    }
};