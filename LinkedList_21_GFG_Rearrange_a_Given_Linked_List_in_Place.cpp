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
	Node* reversell(Node*head){
		if(!head->next) return head;
		Node* revHead = reversell(head->next);
		head->next->next = head;
		head->next = NULL;
		return revHead;
	}
	Node* rearrange(Node*head){
		// O(n^2) solution is to solve bt finding the last node from
		// list and remove it from end and add as the next element of
		// curr node
		// this will take O(n^2) time
		
		// or a better solution is to copy the linked list in an array
		// then swap the array accordingly and copy the modified vector
		// back to list
		
		// or we can find the mid point of linked list using two pointer
		// slow anf fast (tortoise and hare method) and reverse the second
		// half of the linked list and then merge both list alternatively
		Node* temp = head;
		Node*slow = head,*fast = head;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		Node*head2 = slow->next;
		slow->next = NULL;
		Node*head1 = temp;
		Node*revHead = NULL;
		Node*curr = NULL;
		head2 = reversell(head2);
		int cnt = 0;
		while(head1 || head2){
			if(cnt % 2 == 0){
				
			}
			else{

			}
			cnt++;
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
	// Node*temp = head;
	Node*temp = s.rearrange(head);
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}
