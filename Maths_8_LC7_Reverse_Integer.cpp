#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
      long ans = 0;
      while(x != 0){
          if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
          ans = ans*10 + x%10;
          x /= 10;
      }
      return int(ans);
    }
};

int main(){
	int x;
	cin >> x;
	Solution s;
	cout << s.reverse(x) << "\n";
	return 0;
}