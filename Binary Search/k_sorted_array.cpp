#include<bits/stdc++.h>
using namespace std;

string isKSortedArray(int arr[], int n, int k){
        //code here.
        int tmp[n];
        for(int i=0;i<n;i++) tmp[i]=arr[i];
        sort(tmp,tmp+n);
        for(int i=0;i<n;i++){
            int l=0,h=n-1,pos,mid;
            while(l<=h){
                mid=(l+h)/2;
                if(tmp[mid]==arr[i]){
                    pos=mid;
                    break;
                }
                else if(tmp[mid]<arr[i]) l=mid+1;
                else h=mid-1;
            }
            if(abs(pos-i)>k) return "No";
        }
        return "Yes";
}

int main(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<isKSortedArray(arr,n,k)<<endl;    

}