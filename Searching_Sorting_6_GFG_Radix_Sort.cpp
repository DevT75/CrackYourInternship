#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class Solution{
public:
	void countSort(vector<int>&arr,int b,int ex){
		int n = arr.size();
		vector<int> count(10);
		vector<int> output(arr.size());
		for(int i = 0;i < n;i++) count[(arr[i]/ex) % b]++;
		for(int i = 1;i < 10;i++) count[i] += count[i-1];
		for(int i = n - 1;i >= 0;i--){
			output[count[(arr[i] / ex) % b] - 1] = arr[i];
			count[(arr[i]/ex) % b]--;
		}
		for(int i = 0;i < n;i++) arr[i] = output[i];
	}
	void radix_sort(vector<int>&arr){
		int n = arr.size();
		int maxi = *max_element(arr.begin(),arr.end());
		for(int ex = 1;maxi / ex > 0;ex *= 10){
			countSort(arr,10,ex);
		}
	}
};
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &i : arr) cin >> i;
	Solution s;
	s.radix_sort(arr);
	for(auto i : arr) cout << i << " ";
	return 0;
}
