// Ques: In an array count the number of pairs where arr[i]>arr[j] but i<j.(Inversion count)

#include<bits/stdc++.h>
using namespace std;

int merge(int *arr,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int cnt=0;  //number of cross inversions
    int temp[100000];
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            cnt=cnt+mid-i+1; //
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int h=s;h<=e;h++) arr[h]=temp[h];
    return cnt;
}

int inversionCount(int *arr,int s,int e){
    //base case
    if(s>=e) return 0;
    //recursive case
    int mid=(s+e)/2;
    int x=inversionCount(arr,s,mid);
    int y=inversionCount(arr,mid+1,e);
    int z=merge(arr,s,e);
    // cout<<x<<" "<<y<<" "<<z<<endl;
    return x+y+z;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sze=n-1;
    cout<<inversionCount(arr,0,sze);
}