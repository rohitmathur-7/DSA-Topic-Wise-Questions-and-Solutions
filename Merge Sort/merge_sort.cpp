#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;

void merge(int *arr,int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int left[n1],right[n2];
    f(i,0,n1) left[i]=arr[s+i];
    f(i,0,n2) right[i]=arr[mid+1+i];

    int i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;    
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    //if there are some elements left in the left array
    while(i<n1){
        arr[k]=left[i];
        i++;k++;
    }
    //if there are some elements left in the right array
    while(j<n2){
        arr[k]=right[j];
        j++;k++;
    }

}

void mergeSort(int *arr,int s,int e){
    // base case
    if(s>=e) return;

    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n) cin>>arr[i];
    mergeSort(arr,0,n-1);   
    f(i,0,n) cout<<arr[i]<<" ";
    return 0;
}