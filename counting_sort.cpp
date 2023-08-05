#include <iostream>
#include <vector>
using namespace std;
vector<int> countSort(vector<int>&arr){
	int n = arr.size();
	vector<int> ans(n);
	vector<int> count(10);
	for(int i = 0;i < n;i++) count[arr[i]]++;
	for(int i = 1;i < 10;i++) count[i] += count[i-1];
	for(auto i : count) cout << i << " ";
	for(int i = 9;i >= 0;i--){
		count[i] = count[i-1];
	}
	count[0] = 0;
	for(int i = 0;i < n;i++){
		ans[count[arr[i]]] = arr[i];
		count[arr[i]]++;
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &i : arr) cin >> i;
	auto ans = countSort(arr);
	for(auto i : ans) cout << i << " ";
	return 0;
}
