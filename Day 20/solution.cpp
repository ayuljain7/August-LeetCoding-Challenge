/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *end;
    void reverse(ListNode* temp1)
    {
        if(temp1==NULL)
        {
            return ;
        }
        if(temp1->next==NULL)
        {
            end=temp1;
        }
        ListNode *temp=temp1;
        temp1=temp1->next;
        reverse(temp1);
        if(temp1!=NULL)
        {
            temp1->next=temp;
           // cout<<temp1->val<<" ";
            temp->next=NULL;
        }
        //cout<<temp->val<<" ";
    }
    void reorderList(ListNode* head) {
        ListNode * temp1=head;
        ListNode * temp2=head;
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        int count=0;
        while(temp1!=NULL)
        {
            count++;
            temp1=temp1->next;
        }
        temp1=head;
        int count1=count/2;
        while(count1>0)
        {
            temp2=temp1;
            temp1=temp1->next;
            count1--;
        }
        temp2->next=NULL;
        reverse(temp1);
        // temp1=head;
        // while(temp1!=NULL)
        // {
        //     cout<<temp1->val<<" ";
        //     temp1=temp1->next;
        // }
        // temp1=end;
        // while(temp1!=NULL)
        // {
        //     cout<<temp1->val<<" ";
        //     temp1=temp1->next;
        // }
        // int flag=0;
        while(head!=NULL && head->next!=NULL  && end!=NULL && end->next!=NULL)
        {
            temp1=head->next;
            temp2=end->next;
            head->next=end;
            end->next=temp1;
            head=temp1;
            end=temp2;
        }
        if(temp2!=NULL)
        {
            head->next=end;
        }
    }
};