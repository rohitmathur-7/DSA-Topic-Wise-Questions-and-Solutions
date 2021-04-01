//QUES: https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;

bool canKeepCows(int *arr,int n,int c,int minD){
    int cnt=1;
    //place the 1st cow in the 1st stall
    int pos=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[pos]>=minD){
            pos=i;
            cnt++;
            // cout<<"cnt: "<<cnt<<endl;
            if(cnt==c) return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        //binary search
        int s=0;
        int e=arr[n-1] - arr[0]; //maximum possible seperation is arr[n-1] - arr[0]
        int ans; 
        while(s<=e){
            int mid=(s+e)/2;
            // cout<<"mid:  "<<mid<<endl;
            bool can_keep_cows = canKeepCows(arr,n,c,mid);
            if(can_keep_cows){
                ans=mid;  
                s=mid+1;
            }
            else e=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}