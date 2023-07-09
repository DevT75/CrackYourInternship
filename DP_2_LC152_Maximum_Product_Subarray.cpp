#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int max_product(int arr[],int n){
	if(n == 1){
		if(n < 0) return 0;
		else return arr[n-1];
	}
	if(arr[n-1] < 0){
		int op1 = 
	}


	// int temp = max_product(arr,n-1);
	if(arr[n-1] < 0){
		if(temp < 0) return temp*arr[n-1];
		else{
			return max()
		}
	}
	if(temp < 0){
		if(arr[n-1] < 0) return temp*arr[n-1];
		else return arr[n-1];
	}
	else if(temp == 0) return arr[n-1];
	else return max(temp,temp*arr[n-1]);
}

int main(){
	int n;cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++) cin >> arr[i];
	cout << max_product(arr,n);
}
