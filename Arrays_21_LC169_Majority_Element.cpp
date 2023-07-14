#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums) m[i]++;
        int mj = nums.size()/2;
        int ans;
        for(auto i : m){
            if(i.second > mj){
                ans = i.first;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];

    Solution s;
    cout << s.majorityElement(nums) << " ";

    return 0;
}