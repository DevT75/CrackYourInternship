#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        bool ans = true;
        vector<bool> calc(2000,false);
        int temp = n;
        while(temp != 1){
            int newNum = 0;
            while(temp){
                int rem = (temp % 10);
                temp = temp / 10;
                newNum += rem*rem;
            }
            if(!calc[newNum]){
                calc[newNum] = true;
                temp = newNum;
            }
            else{
                return false;
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    Solution s;
    cout << (s.isHappy(n) ? "true" : "false");
    return 0;
}