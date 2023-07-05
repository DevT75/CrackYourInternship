#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0,j = 0;
        int ans = INT_MAX;
        int tot_sum = 0;
        for(auto i : cardPoints) tot_sum += i;
        if(k >= n) return tot_sum;
        int sum = 0;
        while(j < n){
            sum += cardPoints[j];
            if(j - i + 1 < n - k) j++;
            else if(j - i + 1 == n - k){
                ans = min(ans,sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        if(ans == INT_MAX) ans = 0;
        return tot_sum - ans;
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> cardPoints(n);
    for(auto &i : cardPoints) cin >> i;
    Solution s;
    cout << s.maxScore(cardPoints,k) << "\n";
    return 0;
}