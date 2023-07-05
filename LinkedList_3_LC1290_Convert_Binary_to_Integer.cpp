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
	int getValue(ListNode* head,int& mult){
		if(!head->next){
			mult *= 2;
			if(head->val == 0) return 0;
			else return 1;
		}
		int temp = getValue(head->next,mult);
		int ans = mult*(head->val) + temp;
		mult *= 2;
		return ans;
	}
    int getDecimalValue(ListNode* head) {
        int mult = 1;
        int ans = getValue(head,mult);
        return ans;
    }
};

int main(){

	// -1 in the input represents the end of ll

	ListNode* head = takeInput();
	Solution s;
	cout << s.getDecimalValue(head);
	return 0;
}