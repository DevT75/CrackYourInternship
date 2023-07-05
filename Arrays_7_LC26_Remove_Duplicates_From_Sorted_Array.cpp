#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        int ans = nums.size()-count;
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;

    Solution s;
    int len = s.removeDuplicates(nums);
    for(int i = 0;i <  n;i++){
        if(i < len) cout << nums[i] << " ";
        else cout << "_" << " ";
    }
    cout << "\n";
    return 0;
}