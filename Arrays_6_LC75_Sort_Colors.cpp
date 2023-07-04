#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v (3,0);
        for(auto i : nums) v[i]++;
        int i = 0,j = nums.size()-1;
        while(i < v[0]){
            nums[i] = 0;
            i++;
        }
        while(v[1]--){
            nums[i] = 1;
            i++;
        }
        while(v[2]--){
            nums[i] = 2;
            i++;
        }
        // while(i < nums.size()){
        //     if(v[0] != 0){
        //         nums[i] = 0;
        //         v[0]--;
        //     }
        //     else if(v[1] != 0){
        //         nums[i] = 1;
        //         v[1]--;
        //     }
        //     else if(v[2] != 0){
        //         nums[i] = 2;
        //         v[2]--;
        //     }
        //     i++;
        // }
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
}