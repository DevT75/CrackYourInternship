#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 != 0) return false;
        bool ans = true;
        stack<char>st;
        int i = 0;
        while(i < n){
            if(st.empty()){
                if(s[i] == '}' || s[i]==']'||s[i]==')'){
                    ans = false;
                    break;
                }
            }
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(s[i] == '}' && st.top() != '{') {ans = false;break;}
                if(s[i] == ')' && st.top() != '(') {ans = false;break;}
                if(s[i] == ']' && st.top() != '[') {ans = false;break;}
                st.pop();
            }            
            i++;
        }
        if(!st.empty() && i == n) ans = false;
        return ans;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;

    sol.isValid(s) ? cout << "Yes\n" : cout << "No\n";  

    return 0;
}