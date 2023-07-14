#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0,j = 0;
        int n = haystack.length(),m = needle.length();
        if(m > n) return -1;
        int ans = -1;
        for(int i = 0;i < n;i++){
            bool check = true;
            for(int j = i;j < i + m;j++){
                if(haystack[j] != needle[j - i]){
                    check = false;
                    break;
                }
            }
            if(check == true){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
int main(){
    string haystack,needle;
    cin >> haystack >> needle;
    Solution s;
    cout << s.strStr(haystack,needle);
    return 0;
}