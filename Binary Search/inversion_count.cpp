//Ques: 
//Inversion Count : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;

ll merge(ll *arr,ll s,ll mid,ll e,ll *temp){
    ll inv_count=0;
    ll n1=mid-s+1;
    ll n2=e-mid;
    ll left[n1],right[n2];
    f(i,0,n1) left[i]=arr[s+i];
    f(i,0,n2) right[i]=arr[mid+1+i];

    ll i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            temp[k]=left[i];
            i++;    
        }
        else{
            temp[k]=right[j];
            j++;
            inv_count+=(n1-i);
        }
        k++;
    }

    //if there are some elements left in the left array
    while(i<n1){
        temp[k]=left[i];
        i++;k++;
    }
    //if there are some elements left in the right array
    while(j<n2){
        temp[k]=right[j];
        j++;k++;
    }
    
    for(ll i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    return inv_count;
}

ll mergeSort(ll *arr,ll s,ll e,ll *temp){
    ll inv_count=0;
    if(e>s){
        ll mid=(s+e)/2;
        inv_count+=mergeSort(arr,s,mid,temp);
        inv_count+=mergeSort(arr,mid+1,e,temp);
        inv_count+=merge(arr,s,mid,e,temp);
    }
    return inv_count;
}

ll inversion_count(ll *arr,ll n){
    ll temp[n];
    return mergeSort(arr,0,n-1,temp);
}

int main(){
    w(t){
        ll n;
        cin>>n;
        ll arr[n];
        f(i,0,n) cin>>arr[i];
        cout<<inversion_count(arr,n)<<endl;
        // f(i,0,n) cout<<arr[i]<<" ";
    }
    return 0;
}

