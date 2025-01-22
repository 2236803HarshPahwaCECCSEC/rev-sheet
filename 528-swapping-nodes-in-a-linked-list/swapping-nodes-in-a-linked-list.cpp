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
    int length(ListNode* head){
        if(head==NULL) return 0;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp,*start= head;
        int orignalK=k;
        while(--k&&temp!=NULL){
            // Node* firstNode=temp;
            temp=temp->next;
        }
         if(temp == NULL) return head;
        int lastpos=length(head)-orignalK;
        while(lastpos--&&start!=NULL){
            start=start->next;
        }
         if(start == NULL) return head;
        swap(temp->val,start->val);
        return head;
    }
};