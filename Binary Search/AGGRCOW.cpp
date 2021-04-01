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
        //the basic idea is that we will check for different distances that if we can place cows at the particular distance, if we cannot place all the cows at that particular distance then that means we won't be able to place cows at (distance > the current distance), and if were able to place the cows at that particular distance then we want to check if we can place the cows at a greater distance.
        //binary search
        int s=0;
        int e=arr[n-1] - arr[0]; //maximum possible seperation is arr[n-1] - arr[0]
        int ans; 
        while(s<=e){
            int mid=(s+e)/2;
            bool can_keep_cows = canKeepCows(arr,n,c,mid);
            //if we were able to keep the cows, then store in ans the value of mid, it means that for now the answer is mid, but we may get a better answer.
            //also set starting point as mid+1. 
            if(can_keep_cows){
                ans=mid;  
                s=mid+1;
            }
            //if we were not able to keep cows at distance of mid, then ofcourse we won't be able to keep cows at distance > mid, so we will just set end point as mid-1.
            else e=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}