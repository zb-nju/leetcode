#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p1=l1,*p2=l2,*prep1=l1;
        int c=0,t=0;
        while(p1&&p2)
        {
            t=p1->val+p2->val+c;
            p1->val=t%10;
            c=t/10;
            prep1=p1;
            p1=p1->next;
            p2=p2->next;
        }
        if(p2)
        {
            prep1->next=p2;
            p1=p2;
        }
        while(p1)
        {
            t=p1->val+c;
            p1->val=t%10;
            c=t/10;
            prep1=p1;
            p1=p1->next;
        }
        if(c)
            prep1->next=new ListNode(c);
        return l1;
    }
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head=new ListNode(-1);//存放结果的链表
//         ListNode* h=head;//移动指针
//         int sum=0;//每个位的加和结果
//         bool carry=false;//进位标志
//         while(l1!=NULL||l2!=NULL)
//         {
//             sum=0;
//             if(l1!=NULL)
//             {
//                 sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2!=NULL)
//             {
//                 sum+=l2->val;
//                 l2=l2->next;
//             }
//             if(carry)
//                 sum++;
//             h->next=new ListNode(sum%10);
//             h=h->next;
//             carry=sum>=10?true:false;
//         }
//         if(carry)
//         {
//             h->next=new ListNode(1);
//         }
//         return head->next;
//     }
// };