#include <iostream>
using namespace std;

class Solution {
public:
    bool check(int n,int rem){
        if(n <= 0 || rem != 0) return false;
        if(n == 1 && rem == 0) return true;
        return check(n/2,n%2);
    }
    bool isPowerOfTwo(int n) {
        return check(n,0);
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << (s.isPowerOfTwo(n) ? "true" : "false") << "\n";
    return 0;
}