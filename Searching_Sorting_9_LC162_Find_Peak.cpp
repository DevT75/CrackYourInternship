#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0,end = n - 1;
        int idx = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            long prev = mid - 1 >= 0 ? nums[mid-1] : LONG_MIN;
            long next = mid + 1 < n ? nums[mid+1] : LONG_MIN;
            // if(prev == )
            if(nums[mid] > prev && nums[mid] > next){
                idx = mid;
                break;
            }
            else if(nums[mid] < next && nums[mid] > prev) start = mid + 1;
            else if(nums[mid] > next && nums[mid] < prev) end = mid - 1;
            else if(nums[mid] < next && nums[mid] < prev){
                if(prev > next) end = mid - 1;
                else start = mid + 1;
            }
        }
        return idx;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	Solution s;
	int ans = s.findPeakElement(v);
	cout << ans << "\n";
	return 0;
}
