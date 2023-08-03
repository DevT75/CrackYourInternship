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
	Node* zigzag(Node*head){
		Node*temp = head;
		bool chk = true;
		while(temp->next){
			if((chk && temp->data > temp->next->data) ||
			 (!chk && temp->data < temp->next->data)){
			 	int t = temp->data;
			 	temp->data = temp->next->data;
			 	temp->next->data = t;
			}
			chk = !chk;
			temp = temp->next;
		}
		return head;
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
	Node*temp = s.zigzag(head);
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}
