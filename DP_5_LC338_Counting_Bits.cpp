#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return { 0 };
        if(n == 1) return { 0,1 };
        vector<int> ans;
        ans.push_back(0);ans.push_back(1);
        for(int i = 2;i <= n;i++){
            if(i & 1) ans.push_back(1 + ans[i - 1]);
            else ans.push_back(ans[i/2]);
        }
        return ans;
    }
};


int main(){
    int n;
    cin >> n;
    Solution s;
    vector<int> ans = s.countBits(n);
    for(auto i : ans) cout << i << " ";
    return 0;
}