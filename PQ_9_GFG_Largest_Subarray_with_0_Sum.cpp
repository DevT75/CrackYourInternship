#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution{
    public:
    // Prefix sum concept is applied here 
    int maxLen(vector<int>&A, int n){   
        map<int,int> m;
        int i = 0;
        int sum = 0;
        int ans = 0;
        for(int j = 0;j < n;j++){
            sum += A[j];
            if(sum == 0) ans = max(ans,j-i+1);
            if(m.find(sum) != m.end()){
                ans = max(ans,j-m[sum]);
            }
            else m[sum] = j;
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &i : A) cin >> i;
    Solution s;
    cout << s.maxLen(A,n);
    return 0;
}