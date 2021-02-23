/*
 * @Author: zb-nju
 * @Date: 2020-10-18 10:39:49
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-18 11:05:17
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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         stack<ListNode*> s;
//         ListNode* p=head;
//         while(p){
//             s.push(p);
//             p=p->next;
//         }
//         ListNode*now=nullptr,*pre=nullptr;
//         if(n<s.size()){
//             n++;
//             while(n){
//                 pre = now;
//                 now = s.top();
//                 s.pop();
//                 n--;
//             }
//             now->next = pre->next;
//             delete pre;
//         }
//         else{
//             p = head;
//             head = head->next;
//             delete p;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *f=head,*b=head,*p;
        while(n){
            f=f->next;
            n--;
        }
        while(f){
            f=f->next;
            p=b;
            b=b->next;
        }
        if(b==head){
            head=head->next;
            delete b;
        }
        else{
            p->next = b->next;
            delete b;
        }
        return head;
    }
};