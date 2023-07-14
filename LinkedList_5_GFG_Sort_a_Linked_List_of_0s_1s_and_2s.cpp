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
    ListNode* sortList(ListNode* head) {
        ListNode*temp = head;
        map<int,int> m;
        while(temp){
            m[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        while(temp){
            if(m[i] == 0){
                i++;
            }
            else{
                temp->val = i;
                m[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};