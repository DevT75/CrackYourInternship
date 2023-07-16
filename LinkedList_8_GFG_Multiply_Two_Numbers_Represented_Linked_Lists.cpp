#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#define mod 1000000007
using namespace std;

class Solution{
	public:
		long long prod(list<int>&a,list<int>&b){
			long long an = 0,bn = 0;
			for(auto i : a){
				an = ((an*10)%mod + i)%mod;
			}
			for(auto i : b){
				bn = ((bn*10)%mod + i)%mod;
			}
			long long ans = (an*bn)%mod;
			return ans;
		}
};

int main(){
	int n,m;
	cin >> n >> m;
	list<int> a,b;
	for(int i = 0;i < n;i++){
		int temp;cin >> temp;
		a.push_back(temp);
	}
	for(int i = 0;i < m;i++){
		int temp;cin >> temp;
		b.push_back(temp);
	}
	Solution s;
	cout << s.prod(a,b);

	return 0;
}