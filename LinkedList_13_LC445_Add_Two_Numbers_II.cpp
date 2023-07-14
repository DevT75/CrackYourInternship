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
    ListNode*reverseLL(ListNode*head){
        if(head == NULL)return head;
        if(head->next == NULL)return head;
        ListNode*reversedhead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedhead;
    }
    int carry(int sum){
        if(sum > 9) return sum - 9;
        return 0;
    }
    int len(ListNode*head){
        int i = 0;
        ListNode*temp = head;
        while(temp!=NULL){
            temp = temp->next;
            i++;
        }
        return i;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode*temp1 = l1,*temp2 = l2;
        int x = len(l1),y = len(l2);
        if(x > y){
            int t = x - y;
            while(t--){
                ListNode*newNode = new ListNode(0);
                newNode->next = temp2;
                temp2 = newNode;
            }
        }
        else{
            int t = y - x;
            while(t--){
                ListNode*newNode = new ListNode(0);
                newNode->next = temp1;
                temp1 = newNode;
            }
        }
        ListNode*temp = temp1;
        while(temp1 && temp2){
            temp1->val += temp2->val;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ListNode*reverseHead = reverseLL(temp);
        temp = reverseHead;
        while(temp->next){
            int c = carry(temp->val);
            if(temp->val > 9){
                c = temp->val/10;
                temp->val = temp->val%10;
            }
            else{
                temp->val = temp->val;
                c = 0;
            }
            temp->next->val += c;
            temp = temp->next;
        }
        ListNode*ans = reverseLL(reverseHead);
        if(ans->val > 9){
            ListNode*n = new ListNode(ans->val / 10);
            n->next = ans;
            ans->val = ans->val % 10;
            return n;
        }
        return ans;   
    }
};