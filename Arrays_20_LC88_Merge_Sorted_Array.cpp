#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> one(m);
        for(int i = 0;i < m;i++) one[i] = nums1[i];
        int i = 0,j = 0,idx = 0;
        while(i < m && j < n){
            if(one[i] <= nums2[j]){
                nums1[idx++] = one[i++];
            }
            else nums1[idx++] = nums2[j++];
        }
        while(i < m) nums1[idx++] = one[i++];
        while(j < n) nums1[idx++] = nums2[j++];
    }
};


int main(){
    int n,m;
    cin >> m >> n;
    vector<int> nums1(m+n,0),nums2(n);
    for(int i = 0;i < n;i++) cin >> nums2[i];
    for(int i = 0;i < m;i++) cin >> nums1[i];
    Solution s;
    s.merge(nums1,m,nums2,n);
    for(int i = 0;i < m + n;i++) cout << nums1[i] << " ";
    return 0;
}