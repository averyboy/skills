#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

void insert(ListNode* &pListHead,int k)
{
    if(pListHead==NULL)
    {
        pListHead=new ListNode(k);
        return ;
    }
    ListNode* p=pListHead;
    while(p->next)
    {
        p=p->next;
    }
    p->next=new ListNode(k);
    return ;
}
void show(ListNode *head)
{
    ListNode* p=head;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return ;
}
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k<0)
            return NULL;
        ListNode *p1=pListHead,*p2=pListHead;
        int i=0;
        while(i<k-1)
        {
            p1=p1->next;
            i++;
        }
        while(p1->next)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
};

ListNode* reverse(ListNode* head)
{
    ListNode* p=head;
    ListNode* second=p->next;
    p->next=NULL;
    ListNode* third;
    while(second)
    {
        third=second->next;
        second->next=p;
        p=second;
        if(third==NULL)
            return second;
        second=third;
    }
}

int main()
{
    ListNode *head=NULL;
    for(int i=0;i<5;i++)
    {
        insert(head,i);
    }
    show(head);
    // cout<<Solution().FindKthToTail(head,3)->val<<endl;
    ListNode *ans=reverse(head);
    show(ans);
    return 0;
}