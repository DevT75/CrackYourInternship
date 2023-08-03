/*
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.
 */

// I turned it into a graph problem lol
// there is probably a better way to solve this

class Solution {
public:
    void dfs(int src,map<int,vector<int>>&adj,map<int,bool>&vis,vector<int>&ans){
        vis[src] = true;
        ans.push_back(src);
        for(auto node : adj[src]){
            if(!vis[node]) dfs(node,adj,vis,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,int> m;
        map<int,vector<int>> adj;
        map<int,bool> vis;
        int n = adjacentPairs.size();
        for(int i = 0;i < n;i++){
            int a = adjacentPairs[i][0],b = adjacentPairs[i][1];
            vis[a] = vis[b] = false;
            adj[a].push_back(b);adj[b].push_back(a);
            m[a]++;m[b]++;
        }
        int srca = INT_MIN,srcb = INT_MIN;
        for(auto i : m) if(i.second == 1){
            if(srca != INT_MIN) srcb = i.first;
            else srca = i.first;
        }
        vector<int> ans;dfs(srca,adj,vis,ans);
        return ans;
    }
};