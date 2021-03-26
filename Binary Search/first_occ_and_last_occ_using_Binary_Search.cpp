#include<bits/stdc++.h>
using namespace std;

int first_occurence(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int ans;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid] == key){
            ans=mid;
            e=mid-1; //to find the first occ of a element, we have to find in the left part of the array
        }
        else if(arr[mid] > key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int last_occurence(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int ans;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid] == key){
            ans=mid;
            s=mid+1; //to find the last occ of a element, we have to search in the right part of the array
        }
        else if(arr[mid] > key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}


int main(){
    int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    //first and last occurence of the array
    cout<<first_occurence(arr,n,key)<<endl;
    cout<<last_occurence(arr,n,key)<<endl;
}