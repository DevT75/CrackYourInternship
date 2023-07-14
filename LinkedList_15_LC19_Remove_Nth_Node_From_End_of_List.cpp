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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode*temp = head;
        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }
        ListNode*targetNode = nodes[nodes.size()-n];
        ListNode*prev = (n == nodes.size()) ? NULL : nodes[nodes.size()-n-1];
        ListNode*next = (n == 1) ? NULL : nodes[nodes.size()-n+1];
        if(!prev) head=head->next;
        else if(!next) prev->next = NULL;
        else prev->next = next;

        return head;
    }
};