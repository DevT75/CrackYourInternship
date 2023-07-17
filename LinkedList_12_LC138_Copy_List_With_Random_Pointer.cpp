/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*,Node*> newList;
        newList[NULL] = NULL;
        for(auto i = head;i != NULL;i = i->next){
            newList[i] = new Node(i->val);
        }
        for(auto i = head;i != NULL;i = i->next){
            newList[i]->next = newList[i->next];
            newList[i]->random = newList[i->random];
        }
        return newList[head];
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(!head) return NULL;
//         vector<int> ranIdx;
//         vector<Node*> newList;
//         Node*newHead = NULL,*tail = NULL,*temp = head;
//         while(temp){
//             if(!newHead){
//                 newHead = new Node(temp->val);
//                 tail = newHead;
//                 bool flag = false;
//                 int i = 0;
//                 Node*t = head;
//                 while(t){
//                     if(!temp->random) break;
//                     if(temp->random == t){
//                         flag = true;
//                         break;
//                     }
//                     i++;
//                     t = t->next;
//                 }
//                 flag ? ranIdx.push_back(i) : ranIdx.push_back(-1);
//             }
//             else{
//                 tail->next = new Node(temp->val);
//                 bool flag = false;
//                 int i = 0;
//                 Node*t = head;
//                 while(t){
//                     if(!temp->random) break;
//                     if(temp->random == t){
//                         flag = true;
//                         break;
//                     }
//                     i++;
//                     t = t->next;
//                 }
//                 flag ? ranIdx.push_back(i) : ranIdx.push_back(-1);
//                 tail = tail->next;
//             }
//             newList.push_back(tail);
//             temp = temp->next;
//         }
//         for(int i = 0;i < newList.size();i++){
//             if(ranIdx[i] == -1) newList[i]->random = NULL;
//             else newList[i]->random = newList[ranIdx[i]];
//         }
//         return newList[0];
//     }
// };