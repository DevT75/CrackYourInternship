#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v(nums.size() + 1,false);
        int i = 0;
        for(;i < nums.size();i++){
            v[nums[i]] = true;
        }
        int ans;
        i = 0;
        for(;i < nums.size();i++){
            if(!v[i]){
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
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    Solution s;
    cout << s.missingNumber(v) << "\n";
    return 0;
}