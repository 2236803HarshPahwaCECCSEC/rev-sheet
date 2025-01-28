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
    int computeLength(ListNode* head){
        if(head==nullptr)return 0;
        ListNode* temp=head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=computeLength(head);
        int actualn=length-n+1;
        if(actualn==1){
            ListNode* todelete=head;
            head=head->next;
            delete todelete;
            return head;
        }
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(actualn>1){
            prev=temp;
            temp=temp->next;
            actualn--;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};