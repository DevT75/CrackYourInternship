#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cfloat>
#include <map>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0;i < n;i++){
            map<double,int> m;
            for(int j = i + 1;j < n;j++){
                int dy = points[j][1]-points[i][1];
                int dx = points[j][0]-points[i][0];
                double slope;
                if(dx == 0) slope = -DBL_MAX;  
                else slope = double(dy)/double(dx);
                m[slope]++;
                ans = max(ans,m[slope]+1);
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i = 0;i < n;i++) cin >> points[i][0] >> points[i][1];
    Solution s;
    cout << s.maxPoints(points);
    return 0;
}