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
    ListNode* partition(ListNode* head, int x) {
        ListNode*p1 = NULL,*p2 = NULL,*t1 = NULL,*t2 = NULL;
        ListNode*temp = head;
        while(temp){
            if(temp->val < x){
                if(!p1){
                    p1 = new ListNode(temp->val);
                    t1 = p1;
                }
                else{
                    t1->next = new ListNode(temp->val);
                    t1 = t1->next;
                }
            }
            else{
                if(!p2){
                    p2 = new ListNode(temp->val);
                    t2 = p2;
                }
                else{
                    t2->next = new ListNode(temp->val);
                    t2 = t2->next;
                }
            }
            temp = temp->next;
        }
        if(t1) t1->next = p2;
        if(!p1) return p2;
        return p1;
    }
};