// Ques: Print the first occurence of a number

#include<bits./stdc++.h>
using namespace std;

int first_occ(int *arr,int key,int n){
    //base case
    if(n==0) return -1;

    //recursive case
    if(arr[0]==key) return 0;
    int i=first_occ(arr+1,key,n-1);
    if(i==-1) return -1;
    return i+1;
}

int last_occ(int *arr,int key,int n){
    //base case
    if(n==0) return -1;

    //recursive case
    int i=last_occ(arr+1,key,n-1);
    if(i==-1){
        if(arr[0]==key) return 0;
        else return -1;
    }
    return i+1;
}

void all_occ(int *arr,int i,int n,int key){
    if(i==n) return;
    if(arr[i]==key) cout<<i<<",";
    all_occ(arr,i+1,n,key);
}

int main(){
    int arr[]={1,3,2,7,5,6,7,10};
    int key=7;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<first_occ(arr,key,n)<<endl;
    cout<<last_occ(arr,key,n)<<endl;
    all_occ(arr,0,n,key);
}