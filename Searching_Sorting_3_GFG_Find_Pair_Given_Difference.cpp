#include <iostream>
#include <map>
using namespace std;
bool findPair(int arr[], int size, int n){
    //code
    map<int,int> m;
    for(int i = 0;i < size;i++) m[arr[i]]++;
    for(int i = 0;i < size; i++){
        if(n == 0){
            if(m[arr[i]] >= 2) return true;   
        }
        else if(m.find(n+arr[i])!=m.end()) return true;
    }
    return false;
}
int main(){
    int n,size;
    cin >> size >> n;
    int arr[size];
    for(int i = 0;i < size;i++) cin >> arr[i];
    cout << (findPair(arr,size,n) ? "1" : "-1");
    return 0;
}