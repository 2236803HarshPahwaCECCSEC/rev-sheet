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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* curr=new ListNode(0);
        ListNode* returnnode=curr;
        int sum=0;
        while(temp!=nullptr){
            ListNode* check=temp;
            if(temp->val==0){
                returnnode->next=new ListNode(sum);
                returnnode=returnnode->next;
                sum=0;
            }
            else{sum+=temp->val;}
            temp=temp->next;
        }
        return curr->next;
    }
};