#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e){
    int m=(s+e)/2;
    int i=s;
    int j=m+1;
    int k=s;
    int temp[100];
    //using the 2 pointer technique to assign values
    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int h=s;h<=e;h++) arr[h]=temp[h];
}

void mergeSort(int *arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }
    //recursive case
    int m=(s+e)/2;
    //calling mergeSort on first half
    mergeSort(arr,s,m);
    //calling mergeSort on second half
    mergeSort(arr,m+1,e);
    //merging the 2 half
    merge(arr,s,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    //printing the sorted array
    for(int i=0;i<n;i++) cout<<arr[i]<<" , ";
}