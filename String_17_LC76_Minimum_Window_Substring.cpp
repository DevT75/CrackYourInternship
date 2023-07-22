#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int k = t.length();
        if((k > n) || (k == 1 && n == 1 && s[0] != t[0])) return "";
        map<char,int> m;
        for(auto i : t) m[i]++;
        int count = m.size();
        int i = 0;
        pair<int,int> ans = {0,0};
        int len = INT_MAX;
        for(int j = 0;j < n;j++){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0) count--;
            }
            while(count == 0){
                int temp = j-i+1;
                if(len > temp){
                    len = temp;
                    ans = { i,j };
                }
                if(m.find(s[i]) == m.end()){
                    i++;
                    continue;
                }
                m[s[i]]++;
                if(m[s[i]] == 1) count++;
                i++;
            }
        }
        len = ans.second-ans.first+1;
        if((len < t.length()) || (len == 1 && s[ans.first] != t[0])) return "";
        // if(len < t.length()) return ""; 
        return s.substr(ans.first,len);
    }
};
int main(){
	string s,t;cin >> s >> t;
	Solution sol;
	cout << sol.minWindow(s,t);
	return 0;
}