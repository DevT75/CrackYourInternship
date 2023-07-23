#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int tasks, vector<vector<int>>& prerequisites){
        int v = prerequisites.size();
        if(v == 0) return true;
        vector<int> adj[tasks];
        for(vector<int>&i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> inDegree(tasks,0);
        for(int i = 0;i < tasks;i++){
            for(auto j : adj[i]) inDegree[j]++;
        }
        queue<int> q;
        for(int i = 0;i < tasks;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        int i = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            i++;
            for(auto j : adj[temp]){
                inDegree[j]--;
                if(inDegree[j] == 0) q.push(j);
            }
        }
        if(i < tasks) return false;
        return true;
    }
};

int main(){
    int tasks,n_p;
    cin >> n_p >> tasks;
    vector<vector<int>> prereq;
    for(int i = 0;i < n_p;i++){
        int a,b;
        cin >> a >> b;
        prereq.push_back({a,b});
    }
    Solution s;
    cout << (s.canFinish(tasks,prereq) ? "true" : "false");
}