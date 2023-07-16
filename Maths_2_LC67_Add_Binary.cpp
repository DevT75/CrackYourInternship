#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()){
            int t = b.length() - a.length();
            while(t--) a = "0" + a;
        }
        else if(a.length() > b.length()){
            int t = a.length() - b.length();
            while(t--) b = "0" + b;
        }
        int i = a.length() - 1;
        int j = b.length() - 1;
        string c = "0";
        string ans = "";
        while(i >= 0 && j >= 0){
            if(a[i] == '1' && b[j] == '1'){
                if(c == "0"){
                    ans = "0" + ans;
                }
                else{
                    ans = "1" + ans;
                }
                c = "1";
                i--;j--;
            }
            else if(a[i] == '0' && b[j] == '0'){
                if(c == "0") ans = "0" + ans;
                else{
                    ans = "1" + ans;
                    c = "0";
                }
                i--;j--;
            }
            else if((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0')){
                if(c == "0"){
                    ans = "1" + ans;
                }
                else{
                    ans = "0" + ans;
                }
                i--;j--;
            }
        }
        if(c == "1") ans = c + ans;
        return ans;
    }
};
int main(){
	string a,b;
	cin >> a >> b;
	Solution s;
	cout << s.addBinary(a,b);
	return 0;
}
