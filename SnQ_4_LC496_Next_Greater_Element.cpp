#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> m;
        stack<int> s;
        for(int i = nums2.size()-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty() && s.top() <= nums2[i]){
                    s.pop();
                }
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for(int i = 0;i < nums1.size();i++){
            ans[i] = m[nums1[i]];
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n),nums2(m);
    for(auto &i : nums1) cin >> i;
    for(auto &i : nums2) cin >> i;

    Solution s;
    vector<int> ans = s.nextGreaterElement(nums1,nums2);
    for(auto i : ans) cout << i << " ";
    return 0;
}