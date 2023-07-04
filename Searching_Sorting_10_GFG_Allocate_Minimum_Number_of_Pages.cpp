#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int arr[],int n,int maxi,int k){
        int student = 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
            if(sum > maxi){
                student++;
                sum = arr[i];
            }
            if(student > k) return false;
        }
        return true;
    }
    int solver(int arr[],int n,int start,int end,int k){
        if(n < k) return -1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(arr,n,mid,k) == true){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    int findPages(int A[], int N, int M) 
    {
        int sum = 0;
        int maxElem = INT_MIN;
        for(int i = 0;i < N;i++){
            sum += A[i];
            maxElem = max(maxElem,A[i]);
        }
        int ans = solver(A,N,maxElem,sum,M);
        return ans;
    }
};

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0;i < n;i++) cin >> arr[i];

	Solution s;
	cout << s.findPages(arr,n,k) << "\n";

	return 0;
}