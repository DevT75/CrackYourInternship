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
    private:
        ListNode*reverse(ListNode*head,vector<int>&og){
            if(!head->next) {
                og.push_back(head->val);
                return head;
            }
            og.push_back(head->val);
            ListNode*reverseHead = reverse(head->next,og);
            head->next->next = head;
            head->next = NULL;
            return reverseHead;
        }
    public:
        bool isPalindrome(ListNode* head) {
            if(!head || !head->next) return true;
            vector<int> og;
            ListNode*revHead = reverse(head,og);
            int i = 0;
            while(i < og.size() && revHead){
                if(og[i++] != revHead->val) return false;
                revHead = revHead->next;
            }
            return true;
        }
};