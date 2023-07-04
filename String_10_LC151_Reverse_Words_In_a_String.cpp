#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0,j = s.length()-1;
        while(s[i] == ' ') i++;
        while(s[j] == ' ') j--;
        string temp = "";
        // while(i <= j){
        // 	if(s[i] == ' '){
        // 		if(temp != ""){
        // 			st.push(temp);
        // 			temp = "";
        // 		}
        // 		i++;
        // 		continue;
        // 	}
        // 	temp.push_back(s[i++]);
        // }
        // st.push(temp);
        for(i;i <= j;i++){
            if(s[i] == ' '){
            	if(temp != ""){
            		st.push(temp);
            		temp = "";
            	}
                continue;
            }
            temp.push_back(s[i]);
        }
        st.push(temp);
        temp = "";
        while(!st.empty()){
            if(st.size() == 1){
                temp += st.top();
                st.pop();
                break;
            }
            temp += st.top() + " ";
            st.pop();
        }
        return temp;
    }
};

int main(){
	string s;
	getline(cin,s);
	Solution sol;
	cout << sol.reverseWords(s) << "\n";
}