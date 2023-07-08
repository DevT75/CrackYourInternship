#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> preMap;
        int count = 0;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(sum == k) count++;
            if(preMap.find(sum-k)!=preMap.end()){
                count += preMap[sum- k];
            }
            preMap[sum]++;
        }
        return count;
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];

    Solution s;
    cout << s.subarraySum(nums,k) << "\n";
    return 0;
}