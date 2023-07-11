#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int u[n];
        u[0] = 1;
        int p2 = 0,p3 = 0,p5 = 0;
        int n2 = 2*u[p2],n3 = 3*u[p3],n5 = 5*u[p5];
        int ans = u[0];
        for(int i = 1;i < n;i++){
            ans = min(min(n2,n3),n5);
            u[i] = ans;
            if(ans == n2){
                p2++; n2 = 2*u[p2];
            }
            if(ans == n3){
                p3++; n3 = 3*u[p3];
            }
            if(ans == n5){
                p5++;n5 = 5*u[p5];
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.nthUglyNumber(n);
    return 0;
}