#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
	int evalPost(string s){
		stack<int> st;
		int n = s.length();
		for(int i = 0;i < n;i++){
			if(s[i] >= '0' && s[i] <= '9') st.push(s[i]-'0');
			else{
				char op = s[i];
				int a = st.top();st.pop();
				int b = st.top();st.pop();
				if(op == '*') st.push(a*b);
				else if(op == '/') st.push(b/a);
				else if(op == '+') st.push(a + b);
				else if(op == '-') st.push(b - a);
			}
		}
		return st.top();
	}
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.evalPost(s);
	return 0;
}
