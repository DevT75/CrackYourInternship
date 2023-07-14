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
        ListNode*ans = NULL,*tail = ans;
        ListNode*temp1 = list1,*temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                if(!ans){
                    ans = new ListNode(temp1->val);
                    tail = ans;
                }
                else{
                    tail->next = new ListNode(temp1->val);
                    tail = tail->next;
                }
                temp1 = temp1->next;
            }
            else if(temp1->val > temp2->val){
                if(!ans){
                    ans = new ListNode(temp2->val);
                    tail = ans;
                }
                else{
                    tail->next = new ListNode(temp2->val);
                    tail = tail->next;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1){
                if(!ans){
                    ans = new ListNode(temp1->val);
                    tail = ans;
                }
                else{
                    tail->next = new ListNode(temp1->val);
                    tail = tail->next;
                }
                temp1 = temp1->next; 
        }
        while(temp2){
                if(!ans){
                    ans = new ListNode(temp2->val);
                    tail = ans;
                }
                else{
                    tail->next = new ListNode(temp2->val);
                    tail = tail->next;
                }
                temp2 = temp2->next; 
        }
        return ans;
    }
};