#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i = 0,j = 0,idx = 0;
        for(idx; m >= n ? idx < m : idx < n;idx++){
            int temp;
            if(nums1[i] <= nums2[j]){
                temp = nums1[i];
                i++;
            }
            else{
                temp = nums2[j];
                j++;
            }
            ans[idx] = temp;
        }
        nums1[m-1] > nums2[n-1] ? j-- : i--;
        while(i < m){
            ans[idx-1] = nums1[i];
            idx++;
            i++;
        }
        while(j < n){
            ans[idx-1] = nums2[j];
            j++;
            idx++;
        }
        for(int i = 0;i < nums1.size();i++){
            nums1[i] = ans[i];
        }
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