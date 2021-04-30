#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scan(arr) for(ll i=0;i<n;i++) cin>>arr[i];
#define print(arr) for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
#define mod 1000000007
using namespace std;


ll partition(ll *arr,ll s,ll e){
    ll i=(s-1);
    ll pivot=arr[e];
    f(j,s,e){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort(ll *arr,ll s,ll e){
    if(e>s){
        ll pi = partition(arr,s,e);
        quickSort(arr,s,pi-1);
        quickSort(arr,pi+1,e);
    }
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    f(i,0,n) cin>>arr[i];
    quickSort(arr,0,n-1);
    print(arr);
    cout<<endl;
    return 0;
}