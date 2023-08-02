#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string&s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        if(n == 1 || n == 2) return true;
        int i = 0,j = n - 1;
        while(i <= j){
            if(s[i] != s[j]){
                bool op1 = isPalindrome(s,i+1,j);
                bool op2 = isPalindrome(s,i,j-1);
                return op1 || op2;
            }
            i++;j--;
        }
        return true;
    }
};
int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << (sol.validPalindrome(s) ? "yes" : "no");
    return 0;
}