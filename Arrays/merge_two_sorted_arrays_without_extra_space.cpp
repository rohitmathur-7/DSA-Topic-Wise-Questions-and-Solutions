//Question - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#




#include<bits/stdc++.h>
using namespace std;


/*
    ** Most optimal Way **
    Time complexity => O((n+m)*log(n+m))
    O(log(n+m)) for finding out the gap and O(n+m) for traversing on our arrays 
*/
void merge(long long arr1[], long long arr2[], int n, int m){
    //GAP METHOD( smjh ni aaya....bs yaad krlo:) )
    long long gap=ceil((float)(n+m)/2);
    long long p1=0,p2=gap;
    while(gap>=1){
        for(long long i=0;i<n+m,p2<n+m;i++,p2++){
            if(i<n){
                if(p2<n){
                    if(arr1[i]>arr1[p2]){
                        swap(arr1[i],arr1[p2]);
                    }
                }
                else{
                    if(arr1[i]>arr2[p2-n]){
                        swap(arr1[i],arr2[p2-n]);
                    }
                }
            }
            else{
                if(p2<n){
                    if(arr2[i-n]>arr1[p2]){
                        swap(arr2[i-n],arr1[p2]);
                    }
                }
                else{
                    if(arr2[i-n]>arr2[p2-n]){
                        swap(arr2[i-n],arr2[p2-n]);
                    }
                }
            }
        }
        if(gap==1) break;
        gap=ceil((float)gap/2);
        p2=gap;
    }
}

/*
    Time complexity => O(n*m)

// void merge(long long arr1[], long long arr2[], int n, int m) { 
//     // code here
//     for(int i=0;i<n;i++){
//         if(arr1[i]>arr2[0]){
//             swap(arr1[i],arr2[0]);
//             long long first=arr2[0];
//             long long k;
//             for(k=1;k<m && arr2[k]<first;k++) {
//                 arr2[k-1]=arr2[k];
//             } 
//             arr2[k - 1]=first;
//         }
//     }
// }

*/

int main(){
    int n,m;cin>>n>>m;
    long long arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    
    merge(arr1,arr2,n,m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
}