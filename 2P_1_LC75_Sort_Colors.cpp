#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0,mid = 0,end = nums.size() - 1;
        while(mid <= end){
            if(nums[mid] == 2){
                swap(nums[mid],nums[end]);
                end--;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 0){
                swap(nums[start],nums[mid]);
                start++;mid++;
            }
        }
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    s.sortColors(nums);
    for(auto i : nums) cout << i << " ";
    return 0;
}