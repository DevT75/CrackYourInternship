#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the maximum number of cuts.
    
    int maximizeTheCuts(int n, int x, int y, int z){
        vector<long long> dp(n + 1,INT_MIN);
        vector<int> seg = { x, y, z };
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j : seg){
                if(j <= i) dp[i] = max(dp[i],1+dp[i-j]);
            }
        }
        return dp[n] < 0 ? 0 : dp[n];
    }
};

int main(){
    int n,x,y,z;cin >> n >> x >> y >> z;
    Solution s;
    cout << s.maximizeTheCuts(n,x,y,z) << "\n";
    return 0;
}