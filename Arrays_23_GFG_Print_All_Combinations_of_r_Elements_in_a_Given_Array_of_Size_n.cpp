#include <iostream>
#include <vector>
using namespace std;

void combination(vector<int>&v,int l,int r,int i,int k,
	vector<int>&data,vector<vector<int>>&ans){
	if(i == k){
		ans.push_back(data);
		return;
	}
	for(int j = l;j <= r && r-j+1 >= k-i;j++){
		data[i] = v[j];
		combination(v,j+1,r,i+1,k,data,ans);
	}
}
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> v(n);for(auto &i : v) cin >> i;
	vector<vector<int>> ans;
	vector<int> temp(k);
	combination(v,0,v.size()-1,0,k,temp,ans);
	for(auto i : ans){
		for(auto j : i) cout << j << " ";
		cout << "\n";
	}
	return 0;
}
