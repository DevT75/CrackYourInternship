#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// AGGRCOW Spoj
	bool isPossible(vector<int>& arr,int n,int k,int maxi){
		int cows = 1;
		int sum = 0;
		for(int i = 0;i < n;i++){
			sum += arr[i];
			if(sum > maxi){
				cows++;
				sum = arr[i];
			}
			if(cows > k) return false;

		}
		return true;
	}
	int solve(vector<int>& arr,int n,int k){
		if(n < k) return -1;
		int sum = 0;
		int mini = INT_MAX;
		int maxi = INT_MIN;
		int res = -1;
		for(auto i : arr){
			maxi = max(maxi,i);
			mini = min(mini,i);
		}
		sort(arr.begin(),arr.end());
		int start = mini,end = sum;
		while(start <= end){
			int mid = start + (end - start)/2;
			if(isPossible(arr,n,k,mid) == true){
				res = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}
		return res;
	}
};
int main(){
	int t,n,k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector<int> arr(n);
		for(auto &i : arr) cin >> i;
		Solution s;
		cout << s.solve(arr,n,k) << "\n";
	}
	return 0;
}