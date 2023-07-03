#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void solve(string s){
		// I went with unsorted map because it was not specified
		// in the question whether the output shoud be
		// sorted or not
		// unsorted map has O(1) insertion complexity
		// where map has O(log(N))
		unordered_map<char,int> m;
		for(auto i : s) m[i]++;
		for(auto i : m) cout << i.first << " " << i.second << "\n";
	}
};

int main(){
	string str;
	cin >> str;
	Solution s;
	s.solve(str);
	return 0;
}