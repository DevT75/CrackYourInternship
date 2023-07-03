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
    ListNode* middleNode(ListNode* head) {
        if(!head) return NULL;
        ListNode *i = head;
        ListNode *j = head;
        while(j && j->next){
            i = i->next;
            j = j->next->next;
        }
        return i;
    }
    void printLL(ListNode* head){
	    ListNode* temp = head;
	    while(temp!=NULL){
	        cout << temp->val << " ";
	        temp = temp->next;
	    }
    	return;
	}
};

// For +ve Numbers

int main(){
	ListNode* head = takeInput();
	Solution s;
	s.printLL(s.middleNode(head));
	return 0;
}