#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = -1000;
        int mx2 = -1000;
        int mx3 = -1000;
        int mn1 = 1000;
        int mn2 = 1000;
        int mn3 = 1000;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] >= mx1){
                mx3 = mx2;
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if(nums[i] >= mx2){
                mx3 = mx2;
                mx2 = nums[i];
            }
            else if(nums[i] > mx3) mx3 = nums[i];

            if(nums[i] <= mn1){
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(nums[i] < mn2) mn2 = nums[i];
        }
        return max(mx1*mx2*mx3,mx1*mn1*mn2);
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    cout << s.maximumProduct(nums);
    return 0;
}