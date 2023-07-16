#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// I should make a function to return the opposite
// i.e. for a given string return the associated column number

class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> alph(27);
        alph[0] = 'Z';
        for(int i = 1;i <= 26;i++){
            alph[i] = 'A' + i - 1;
        }
        int temp = columnNumber;
        string ans = "";
        while(temp != 0){
            if(temp <= 26){
                ans.push_back(alph[temp]);
                break;
            }
            ans.push_back(alph[temp%26]);
            temp = (temp-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.convertToTitle(n);
    return 0;
}