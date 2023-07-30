#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> ss;
        int n = s.length();
        for(int i = 0;i < n;i++){
            if(s[i] != ']') ss.push(s[i]);
            else{
                string temp = "";
                while(ss.top() != '['){
                    temp += ss.top();
                    ss.pop();
                }
                reverse(temp.begin(),temp.end());
                ss.pop();
                int num = 0;
                int k = 1;
                while(!ss.empty() && isdigit(ss.top())){
                    num += k*(ss.top()-'0');k *= 10;
                    ss.pop();
                }
                int sz = temp.length();
                while(num--){
                    for(int i = 0;i < sz;i++) ss.push(temp[i]);
                }
            }
        }
        string ans = "";
        while(!ss.empty()){
            ans += ss.top();
            ss.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.decodeString(s);
	return 0;
}
