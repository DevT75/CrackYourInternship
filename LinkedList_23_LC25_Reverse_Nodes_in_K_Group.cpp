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
    int len(ListNode*head){
        if(!head) return 0;
        ListNode*temp = head;int i = 0;
        while(temp){
            i++;temp=temp->next;
        }
        return i;
    }
    ListNode*reverse(ListNode*head){
        if(!head || !head->next) return head;
        ListNode*reverseHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return reverseHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == len(head)) return reverse(head);
        if(k <= 0 || k > len(head) || !head || !head->next) return head;
        // if(!head || !head->next) return head;
        ListNode*temp=head,*prev=NULL,*next=temp->next;
        int i = 0;
        while(next && i < k){
            temp->next = prev;
            prev = temp;
            temp = next;
            next = next->next;
            i++;
        }
        ListNode*kreverse = reverseKGroup(temp,k);
        head->next = kreverse;
        return prev;
    }
};