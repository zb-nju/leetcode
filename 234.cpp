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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;

        ListNode *firstHalfEnd = findMiddle(head);
        ListNode *secondHalfHead = reverse(firstHalfEnd->next);

        ListNode *p1 = head, *p2 = secondHalfHead;
        bool flag = true;
        while(p2 != nullptr && flag){
            if(p1->val == p2->val){
                p1 = p1->next;
                p2 = p2->next;
            }else{
                flag = false;
            }
        }
        firstHalfEnd->next = reverse(secondHalfHead);
        return flag;
    }

    ListNode* reverse(ListNode* head){
        if(head == nullptr)
            return nullptr;
        ListNode *pre = nullptr, *now = head, *next = head->next;
        while(now){
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        return pre;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};