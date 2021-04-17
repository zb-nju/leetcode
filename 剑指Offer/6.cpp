#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> ans = reversePrint(head->next).push_back(head->val);
        return ans;
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int>ans;
        stack<int>s;
        ListNode *p = head;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};