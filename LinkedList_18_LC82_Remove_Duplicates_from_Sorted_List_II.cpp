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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        map<int,int> arr;
        while(head){
            arr[head->val]++;
            head = head->next;
        }
        ListNode* newHead = NULL,*tail = NULL;
        for(auto i : arr){
            if(i.second > 1 || i.second == 0) continue;
            else{
                if(!newHead){
                    newHead = new ListNode(i.first);
                    tail = newHead;
                }
                else{
                    tail->next = new ListNode(i.first);
                    tail = tail->next;
                }
            }
        }
        return newHead;
    }
};