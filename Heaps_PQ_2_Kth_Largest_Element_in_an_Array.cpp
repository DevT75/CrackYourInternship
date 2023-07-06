#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i : nums) pq.push(i);
        int temp; 
        while(k--){
            temp = pq.top();
            pq.pop();
        }
        return temp;
    }
};

int main(){
    int n,k;cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    cout << s.findKthLargest(nums,k) << "\n";
    return 0;
}