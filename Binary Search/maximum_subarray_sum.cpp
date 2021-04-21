/*
https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/

Ques:
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7. NOTE:- please solve this problem using Divide and Conquer instead of kadane's algorithm.

Input Format
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

ll maxCrossArray(ll n,ll *arr,ll s,ll e,ll mid){
    //for the left part, we want to get the max suffix sum
    ll left_ans=LLONG_MIN;
    ll l=0;
    for(ll i=mid;i>=s;i--){
        l+=arr[i];
        if(l>left_ans) left_ans=l;
    }
    //for the right part, we want to get the max prefix sum
    ll right_ans=LLONG_MIN;
    ll r=0;
    for(ll i=mid+1;i<=e;i++){
        r+=arr[i];
        if(r>right_ans) right_ans=r;
    }
    ll ans=left_ans+right_ans;
    return max(max(right_ans,left_ans),ans);
}


ll maxSumArray(ll n,ll *arr,ll s,ll e){
    //there is only 1 element present
    if(s==e){
        return arr[s];
    }

    ll mid=(s+e)/2;

    return max(max(maxSumArray(n,arr,s,mid),maxSumArray(n,arr,mid+1,e)) , maxCrossArray(n,arr,s,e,mid));
}


int main(){
    w(t){
        ll n;
        cin>>n;
        ll arr[n];
        f(i,0,n){
            cin>>arr[i];
        }
        cout<<maxSumArray(n,arr,0,n-1)<<endl;
    }

    return 0;
}