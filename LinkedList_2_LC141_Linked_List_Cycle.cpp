#include <bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};
    ListNode*takeInput(){
        ListNode* head = NULL,*tail = NULL;
        int n;
        cin >> n;
        while(n != -1){
            if(!head){
                head = new ListNode(n);
                tail = head;
            }
            else{
                tail->next = new ListNode(n);
                tail = tail->next;
            }
            cin >> n;
        }
        return head;
    }
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool ans = false;
        ListNode* i = head,*j = head;
        while(j && j->next){
            i = i->next;
            j = j->next->next;
            if(i == j) return true;
        }

        return ans;
    }
};
int main(){
    ListNode* head = takeInput();
    Solution s;
    s.hasCycle(head) ? cout << "true\n" : cout << "false\n"; 
    return 0;
}