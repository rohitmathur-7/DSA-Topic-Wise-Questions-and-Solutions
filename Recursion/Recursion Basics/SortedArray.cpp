#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr,int n){
    //base case
    if(n==1) return 1;
    //recursive case
    if((arr[0]<arr[1]) and isSorted(arr+1,n-1)){
        return true;
    }
    return false;
}

int main(){
    int arr[]={1,2,3,14,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,n)<<endl;
}