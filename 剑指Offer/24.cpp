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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        stack<ListNode*> s;
        ListNode* p = head;
        while(p){
            s.emplace(p);
            p = p->next;
        }
        p = head = s.top();
        s.pop();
        while(!s.empty()){
            p->next = s.top();
            p = p->next;
            s.pop();
        }
        p->next = nullptr;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* p = head, *pre = nullptr, *next = nullptr;
        while(p){
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        head = pre;
        return head;
    }
};