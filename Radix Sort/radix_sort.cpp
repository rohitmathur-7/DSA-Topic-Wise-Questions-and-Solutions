#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define w(t) ll t;cin>>t;while(t--)
#define mod 1000000007
using namespace std;

void count_sort(int *arr,int n,int pos){
    //here the range is from 0-9 bcz we are going to consider the numbers at ones ,tens and so on..which can be in the range 0-9 only.
    int count[10]={0};
    f(i,0,n){
        count[(arr[i]/pos)%10]++;
    }
    f(i,1,10){
        count[i]+=count[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[--count[(arr[i]/pos)%10]]=arr[i];
    }
    f(i,0,n){
        arr[i]=b[i];
    }
}

void radix_sort(int *arr,int n){
    int mx=*(max_element(arr,arr+n));

    for(int pos=1;(mx/pos)>0;pos*=10){
        count_sort(arr,n,pos);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n) cin>>arr[i];
    radix_sort(arr,n);
    f(i,0,n) cout<<arr[i]<<" ";

    return 0;
}