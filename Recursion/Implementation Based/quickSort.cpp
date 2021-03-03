#include<iostream>
using namespace std;

int partition(int *arr,int s,int e){
    int i=s-1;
    int j=s;
    int pivot=arr[e];
    for(;j<=e-1;){
        if(arr[j]<=pivot){
            i=i+1;;
            swap(arr[i],arr[j]);
        }
        j=j+1;
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort(int *arr,int s,int e){
    //base case
    if(s>=e) return;
    //recursive case
    int pivot=partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}