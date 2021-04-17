#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numA = 0, numB = 0;
        ListNode *pA = headA, *preA = nullptr, *pB = headB, *preB = nullptr;
        while(pA){
            preA = pA;
            pA = pA->next;
            numA++;
        }
        while(pB){
            preB = pB;
            pB = pB->next;
            numB++;
        }
        if(preA != preB)
            return nullptr;
        pA = headA; pB = headB;
        while(numA > numB){
            pA = pA->next;
            numA--;
        }
        while(numB > numA){
            pB = pB->next;
            numB--;
        }
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};