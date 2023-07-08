#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    inline int dist(vector<int>&a,vector<int>&b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    // bool checkDim(vector<pair<int,int>>& sq){
    //     int a = dist(sq[0],sq[1]);
    //     int b = dist(sq[1],sq[3]);
    //     int c = dist(sq[3],sq[2]);
    //     int d = dist(sq[2],sq[0]);
    //     bool op1 = a == b && b == c && c == d && d == a;
    //     bool op2 = dist(sq[0],sq[3]) == dist(sq[1],sq[2]);
    //     return op1 && op2;
    // }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 || p2 == p3 || p3 == p4 || p2 == p4 || p1 == p4 || p1 == p3) return false;
        vector<int> v(6);
        v[0]=dist(p1,p2);v[1]=dist(p2,p3);v[2]=dist(p3,p4);v[3]=dist(p2,p4);v[4]=dist(p1,p4);v[5]=dist(p1,p3);
        sort(v.begin(),v.end());
        if(v[4] == v[5] && v[0] == v[1] && v[1]==v[2] && v[2] == v[3]) return true;
        return false;
    }
};
int main(){
    vector<int> p1(2),p2(2),p3(2),p4(2);
    cin >> p1[0] >> p1[1] >> p2[0] >> p2[1];
    cin >> p3[0] >> p3[1] >> p4[0] >> p4[1];
    Solution s;
    cout << (s.validSquare(p1,p2,p3,p4) ? "true" : "false") << "\n";
    return 0;
}