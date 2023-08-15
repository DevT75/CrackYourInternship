/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void explore(Node*head,queue<Node*>&q){
        if(!head) return;
        q.push(head);
        if(head->child) explore(head->child,q);
        if(head->next) explore(head->next,q);
        return;
    }
    Node* flatten(Node* head) {
        queue<Node*> q;
        explore(head,q);
        Node*newHead = q.front();
        if(q.empty()) return head;
        newHead->next = NULL;
        newHead->child = NULL;
        Node*tail = newHead;
        q.pop();
        while(!q.empty()){
            Node*temp = q.front();
            temp->child = NULL;
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
            q.pop();
        }
        tail->next = NULL;
        return newHead;
    }
};

// class Solution {
// public:
//     Node* flatten(Node* head){
//         if(!head) return head;
//         Node* temp = head;
//         while(temp){
//             if(temp->child != NULL){
//                 Node*next = temp->next;
//                 temp->next = temp->child;
//                 temp->next->prev = temp;
//                 temp->child = NULL;
//                 Node*curr = temp;
//                 while(curr && curr->next){
//                     curr = curr->next;
//                 }
//                 curr->next = next;
//                 if(curr->next) curr->next->prev = curr;
//             }
//             temp = temp->next;
//         }
//         return head;
//     }
// };