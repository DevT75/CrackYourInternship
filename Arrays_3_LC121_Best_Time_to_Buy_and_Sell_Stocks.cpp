#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowPrice=INT_MAX,ans = 0;
        for(int i = 0;i < prices.size();i++){
            lowPrice = min(lowPrice,prices[i]);
            ans = max(ans,prices[i]-lowPrice);
        }
        return ans;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	cout << s.maxProfit(nums) << "\n";
}