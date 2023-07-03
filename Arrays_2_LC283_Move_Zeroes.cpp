#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;
        int i = 0,j = i + 1;
        while(j < nums.size()){
            if(nums[i] == 0){
                if(nums[j] != 0){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            else{
                i++;j++;
            }

        }
        return;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	s.moveZeroes(nums);

	for(auto i : nums) cout << i << " ";
	return 0;
}