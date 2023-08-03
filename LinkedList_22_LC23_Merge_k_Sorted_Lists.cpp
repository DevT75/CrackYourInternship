/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
 */
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
class cmp{
public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val < b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int k = lists.size();
       priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
       for(int i = 0;i < k;i++){
           ListNode*temp = lists[i];
           while(temp){
               pq.push(temp);
               temp = temp->next;
           }
       }
       ListNode*head = NULL;
       while(!pq.empty()){
           ListNode*temp = pq.top();
           pq.pop();
           temp->next = head;
           head = temp;
       }
       return head;
    }
};