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
        pair<ListNode*,ListNode*> reverse(ListNode* head,int n){
            if(n == 1){
                if(!head) return { head,NULL };
                else return { head,head->next };
            }
            auto reverseHead = reverse(head->next,n-1);
            head->next->next = head;
            head->next = NULL;
            return reverseHead;
        }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right - left == 0) return head;
        ListNode*temp = head; int i = 1;
        pair<ListNode*,ListNode*> r;
        ListNode*pre = NULL;
        while(temp){
            if(i == left){
                r = reverse(temp,right-left+1);
                if(pre) pre->next = r.first;
                else head = r.first;
                temp->next = r.second;
                break;
            }
            i++;
            pre = temp;
            temp = temp->next;
        }
        return head;
    }
};