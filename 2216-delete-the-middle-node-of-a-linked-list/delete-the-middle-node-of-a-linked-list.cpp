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
    ListNode* returnMiddlePos(ListNode* slow,ListNode* fast){
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
                slow=slow->next;
                // fast=fast->next;
            
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||head->next==nullptr){
            return nullptr;
        }
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* slow=head;
        slow=returnMiddlePos(slow,curr);
        if (slow == head) {  
            head = head->next;
            delete slow;
            return head;
        }
        prev=head;

        while(prev->next!=slow){
            prev=prev->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;



    }
};