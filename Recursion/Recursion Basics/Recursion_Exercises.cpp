#include<bits/stdc++.h>
using namespace std;

// Ex1: Do binary search using recursion
// int binary_search(int *arr,int l,int r,int element){
//     int mid=l+(r-l)/2;
//     if(arr[mid]==element){
//         return mid;
//     }
//     if(element < arr[mid]){
//         return binary_search(arr,0,mid-1,element);
//     }
//     return binary_search(arr,mid+1,r,element);
// }

// int main(){
//     int arr[]={1,2,3,4,5,6,7,8,9,10};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int element;
//     cin>>element;
//     cout<<binary_search(arr,0,n-1,element)<<endl;
// }

// Ex2: Recursive function to perform power(a,n)

// int pow(int a,int n){
//     if(n==1) return a;
//     return a*pow(a,n-1);
// }

// int main(){
//     int a,n;
//     cin>>a>>n;
//     cout<<pow(a,n)<<endl;
// }


// Ex3: Recursive function to multiply 2 numbers a and b without using * operator

// int multiply(int a,int b){
//     if(b==1) return a;
//     return a+multiply(a,b-1);
// }

// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<multiply(a,b)<<endl;
// }

