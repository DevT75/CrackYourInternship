#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        stack<int> st;
        int temp = num;
        int tnth = 1;
        while(temp){
            st.push(tnth*(temp%10));
            temp = temp/10;
            tnth *= 10;
        }
        tnth /= 10;
        string ans = "";
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(tnth == 1000){
                int cnt = t/tnth;
                while(cnt--) ans.push_back('M');
            }
            else if(tnth == 100){
                if(t == 900) ans += "CM";
                else if(t == 400) ans += "CD";
                else if(t >= 500){
                    int cnt = t/500;
                    int rem = (t % 500)/100;
                    while(cnt--) ans.push_back('D');
                    while(rem--) ans.push_back('C');
                }
                else{
                    int cnt = t/100;
                    while(cnt--) ans.push_back('C');
                }
            }
            else if(tnth == 10){
                if(t == 90) ans += "XC";
                else if(t == 40) ans += "XL";
                else if(t >= 50){
                    int cnt = t/50;
                    int rem = (t % 50)/10;
                    while(cnt--) ans.push_back('L');
                    while(rem--) ans.push_back('X');
                }
                else{
                    int cnt = t/10;
                    while(cnt--) ans.push_back('X');
                }
            }
            else{
                if(t == 0) continue;
                if(t == 9) ans += "IX";
                else if(t == 4) ans += "IV";
                else if(t >= 5){
                    int cnt = t/5;
                    int rem = (t % 5);
                    while(cnt--) ans.push_back('V');
                    while(rem--) ans.push_back('I');
                }
                else{
                    int cnt = t;
                    while(cnt--) ans.push_back('I');
                }
            }
            tnth /= 10;
        }
        return ans;
    }
};

int main(){
    // 1 <= n <= 3999 otherwise ans would be wrong from
    // this solution
    int n;
    cin >> n;
    Solution s;
    cout << s.intToRoman(n);
}