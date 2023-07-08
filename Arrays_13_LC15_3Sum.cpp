#include <iostream>
#include <queue>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n - 2;i++){
            int target = -1*nums[i];
            int start = i + 1,end = n - 1;
            while(start < end){
                if(nums[start] + nums[end] == target){
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[start];
                    temp[2] = nums[end];
                    s.insert(temp);
                    int m = nums[end];
                    while(start < end && m == nums[end]) end--;
                }
                else if(nums[start] + nums[end] < target) start++;
                else end--;
            }
        }
        for(auto i : s) ans.push_back(i);
        return ans;
    }
};

int main(){
    int n,target;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];

    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);
    for(auto &i : ans){
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}