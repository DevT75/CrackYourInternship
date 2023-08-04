#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length();
        int k = p.length();
        if(k > n) return "-1";
        if(k == 1 && n == 1 && s[0] != p[0]) return "";
        int m[26] = { 0 };int count = 0;
        for(int i = 0;i < p.length();i++){
            if(m[p[i]-'a'] == 0) count++;
            m[p[i]-'a']++;
        }
        int i = 0;
        pair<int,int> ans = {0,1000000};
        for(int j = 0;j < n;j++){
            m[s[j]-'a']--;
            if(m[s[j]-'a'] == 0) count--;
            while(count == 0 && i <= j){
                if(ans.second - ans.first + 1 > (j - i + 1)) ans = { i,j };
                m[s[i]-'a']++;
                if(m[s[i]-'a'] == 1) count++;
                i++;
            }
        }
        if(ans.second == 1000000) return "-1";
        string temp = "";
        for(int i = ans.first;i <= ans.second;i++) temp.push_back(s[i]);
        return temp;
    }
};
int main(){
	string s,t;cin >> s >> t;
	Solution sol;
	cout << sol.minWindow(s,t);
	return 0;
}