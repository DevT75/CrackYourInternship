#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long solve(vector<int>&nums,vector<int>&cost,int x){
        long long ans = 0;
        for(int i = 0;i < nums.size();i++)
            ans += 1L*abs(nums[i]-x)*cost[i];
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int start = 0,end = 1e6,x;long long ans = solve(nums,cost,1);
        while(start < end){
            x = start + (end-start)/2;
            auto op1 = solve(nums,cost,x),op2 = solve(nums,cost,x + 1);
            ans = min(op1,op2);
            if(op1 < op2){
                end = x;
            }
            else start = x + 1;
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n),cost(n);
    for(auto &i : nums) cin >> i;
    for(auto &i : cost) cin >> i;
    Solution s;
    cout << s.minCost(nums,cost);
    return 0;
}