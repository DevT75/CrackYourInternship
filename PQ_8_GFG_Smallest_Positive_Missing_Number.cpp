#include <iostream>
#include <utility>
using namespace std;
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int i = 0;
       for(int i = 0;i < n;i++){
            if(arr[i] > 0 && arr[i] <= n){
                int temp = arr[i];
                int currPos = arr[i]-1;
				if(arr[currPos] != temp){
                	swap(arr[i],arr[arr[i]-1]);
                	i--;
            	}
            }
        }
        int ans = n;
        for(int i = 0;i < n;i++){
            if(arr[i] != i + 1) return i + 1;
        }
        return ans + 1;
    } 
};
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    Solution s;
    cout << s.missingNumber(arr,n);
    return 0;
}