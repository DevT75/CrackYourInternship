#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        if(i == j) return true;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void solve(int idx,string&s,vector<string>&temp,vector<vector<string>>&ans,int n){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i < n;i++){
            if(isPalindrome(idx,i,s)){
                int len = abs(i-idx);
                temp.push_back(s.substr(idx,len + 1));
                solve(i + 1,s,temp,ans,n);
                temp.pop_back();
            }
        }
    } 
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0,s,temp,ans,s.length());
        return ans;
    }
};
int main(){
	string s;
	cin >> s;
	Solution sol;
	auto ans = sol.partition(s);
	for(auto i : ans){
		for(auto j : i) cout << j << " ";
		cout << "\n";
	}
	return 0;
}
