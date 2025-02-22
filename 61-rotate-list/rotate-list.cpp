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
        if(head==nullptr) return 0;
        ListNode* temp=head;
        int length=0;
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int length=computeLength(head);
        ListNode* temp1=head;
        vector<int>temp;
        if(k!=0) k = k % length;
        if(k==0) return head;
        int val=length-k;
        while(val--){
            temp1=temp1->next;
        }
        while(temp1!=nullptr){
            temp.push_back(temp1->val);
            temp1=temp1->next;
        }
        temp1=head;
        for(int i=0;i<length-k;i++){
            temp.push_back(temp1->val);
            temp1=temp1->next;
        }
        temp1=head;
        int i=0;
        while(temp1!=nullptr){
            temp1->val=temp[i];
            temp1=temp1->next;
            i++;
        }
        return head;
 }
};