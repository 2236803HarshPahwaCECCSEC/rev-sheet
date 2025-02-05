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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr&&list2==nullptr) return nullptr;
        if(list1==nullptr&&list2!=nullptr) return list2;
        if(list1!=nullptr&&list2==nullptr) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        vector<int> list;
        while(temp1!=nullptr||temp2!=nullptr){
            if(temp1) {
                list.push_back(temp1->val);
                temp1=temp1->next;}
            if(temp2){
                list.push_back(temp2->val);
                temp2=temp2->next;
            }
        }
        ListNode* temp=nullptr;
        sort(list.begin(),list.end());
        temp=new ListNode(list[0]);
       ListNode*  curr=temp;
        int i=1;
        while(i<list.size()){
            curr->next=new ListNode(list[i]);
            curr=curr->next;
            i++;
        }
        return temp;
    }
};