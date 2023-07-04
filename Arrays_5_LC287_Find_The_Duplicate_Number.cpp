#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i : nums) m[i]++;
        int ans = -1;
        for(auto i : nums){
            if(m[i] > 1){
                ans = i;
                break;
            }
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
	cout << s.findDuplicate(nums) << "\n";
	return 0;
}
