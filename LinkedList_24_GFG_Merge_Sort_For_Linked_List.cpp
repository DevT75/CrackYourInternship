#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	int data;
	Node*next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};
class Solution{
public:
	void split(Node*head,Node**a,Node**b){
		Node*slow = head,*fast = head->next;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		*b = slow->next;
		slow->next = NULL;
		*a = head;
	}
	Node*merge(Node*a,Node*b){
		Node*result = NULL;
		if(!a) return b;
		if(!b) return a;
		if(a->data <= b->data){
			result = a;
			result->next = merge(a->next,b);
		}
		else{
			result = b;
			result->next = merge(a,b->next);
		}
		return result;
	}
	void mergeSort(Node**head){
		Node*h = *head;
		if(!h || !h->next) return;
		Node*a,*b;
		split(h,&a,&b);
		mergeSort(&a);
		mergeSort(&b);
		*head = merge(a,b);
	}
};
int main(){
	Node*head = NULL,*tail = NULL;
	int n;
	cin >> n;
	// -1 represents end point of list
	while(n != -1){
		if(!head){
			head = new Node(n);
			tail = head;
		}
		else{
			tail->next = new Node(n);
			tail = tail->next;
		}
		cin >> n;
	}
	Solution s;
	s.mergeSort(&head);
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	return 0;
}
