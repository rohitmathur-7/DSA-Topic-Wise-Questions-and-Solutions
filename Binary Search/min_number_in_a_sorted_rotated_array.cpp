//QUES: https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1/?page=1&category[]=Binary%20Search&query=page1category[]Binary%20Search

#include<bits/stdc++.h>
using namespace std;

int min_num(int *arr,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==0 || (arr[mid]<arr[mid-1])) return arr[mid];
        else if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else{
            high=mid;
        }    
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<min_num(arr,n)<<endl;
}