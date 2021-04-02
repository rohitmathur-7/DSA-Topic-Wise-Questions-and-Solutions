#include<bits/stdc++.h>
using namespace std;

int b_search(int a,int *arr2,int n){
    int s=0;
    int e=n-1;
    int cnt=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr2[mid]<=a){
            s=mid+1;
            cnt=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return cnt;
}

void ans(int *arr1,int *arr2,int n,int m){
    sort(arr2,arr2+n);
    for(int i=0;i<m;i++){
        cout<<b_search(arr1[i],arr2,n)<<" ";
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m],arr2[n];
    for(int i=0;i<m;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];

    ans(arr1,arr2,n,m);
    return 0;
}
    