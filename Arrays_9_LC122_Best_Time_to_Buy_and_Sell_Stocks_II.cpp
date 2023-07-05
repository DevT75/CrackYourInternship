#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currStonk = prices[0];
        for(int i = 1;i < prices.size();i++){
            if(prices[i] >= currStonk && currStonk != -1){
                profit += prices[i]-currStonk;
                if(i + 1 < prices.size() && prices[i] < prices[i+1]){
                    currStonk = prices[i];
                }
                else currStonk = -1;
            }
            else currStonk = prices[i];
        }
        return profit;
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