#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0,og = x;
        while(x != 0){
            rev = rev*10 + x%10;
            x /= 10;
        }
        if(og + (rev-og)/2 == og) return true;
        else return false;
    }
};

int main(){
	int x;
	cin >> x;
	Solution s;
	cout << (s.isPalindrome(x) ? "true" : "false");
	return 0;
}
