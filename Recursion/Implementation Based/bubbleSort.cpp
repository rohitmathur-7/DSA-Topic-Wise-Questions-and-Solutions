#include<bits/stdc++.h>
using namespace std;

//swap 2 elements
// void swap_elements(int *aj,int *aj1){
//     int temp=*aj;
//     *aj=*aj1;
//     *aj1=temp;
// }

//iterative approach
void iterative_bubbleSort(int *arr,int n){    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

//partially recursive approach
void bubbleSort(int *arr,int n){
    //base case
    if(n==1) return;
    //recursive case
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,n-1);
}

//completely recursive approach
void bubbleSortRecursive(int *arr,int j,int n){
    //base case
    if(n==1) return;

    if(j==n-1) return bubbleSortRecursive(arr,0,n-1);
    //recursive case
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    bubbleSortRecursive(arr,j+1,n);
    return;
}

int main(){
    int arr[]={5 ,1 ,4 ,2 ,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    // iterative_bubbleSort(arr,n); //iterative approach
    // bubbleSort(arr,n); //partially recursive approach
    // bubbleSortRecursive(arr,0,n); //completely recursive approach
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}