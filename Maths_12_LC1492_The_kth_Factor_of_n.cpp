#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int kthFactor(int n, int k) {
        int curr = 0;
        for(int i = 1;i <= n;i++){
            if(n % i == 0) curr++;
            if(curr == k) return i;
        }
        return -1;
    }
    // int kthFactor(int n, int k) {
    //     vector<int> factors;
    //     for(int i = 1;i <= n;i++){
    //         if(n % i == 0) factors.push_back(i);
    //     }
    //     if(k > factors.size()) return -1;
    //     return factors[k-1];
    // }
};

int main(){
    int n,k;
    cin >> n >> k;
    Solution s;
    cout << s.kthFactor(n,k);
    return 0;
}