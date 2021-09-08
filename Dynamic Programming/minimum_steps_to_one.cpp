#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0,i<n;i++) cout<<arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
                     
/*
Calculating minimum steps to reach 1 from n using Bottom-Up Dp.
        T.C - O(N)
        S.C - O(N)
*/
ll min_steps_bottom_up_dp(ll n){

    ll dp[n+1];
    dp[1]=0;

    f(i,2,n+1){
        if(i%2==0 && i%3==0){
            dp[i]=min({dp[i-1],dp[i/2],dp[i/3]})+1;
        }
        else if(i%2==0){
            dp[i]=min(dp[i-1],dp[i/2])+1;
        }
        else if(i%3==0){
            dp[i]=min(dp[i-1],dp[i/3])+1;
        }
        else{
            dp[i]=dp[i-1]+1;
        }
    }

    return dp[n];
}


/*
Calculating minimum steps to reach 1 from n using Top-Down Dp.
        T.C - O(N)
        S.C - O(N)
*/
ll min_steps_top_down_dp(ll n,ll dp[]){ 
    //base case
    if(n==1) return 0;

    //rec case
    //lookup is n is already computed
    if(dp[n]!=0) return dp[n];    
    //compute if dp[n] is not known(for first time)
    ll op1,op2,op3;
    op1=op2=op3=LLONG_MAX;

    if(n%2==0){
        op1=min_steps_top_down_dp(n/2,dp)+1;
    }
    if(n%3==0){
        op1=min_steps_top_down_dp(n/3,dp)+1;
    }
    op3=min_steps_top_down_dp(n-1,dp)+1;

    ll ans=min({op1,op2,op3});

    return dp[n]=ans;
}

int main(){
 
    ll n;cin>>n;
    ll dp[n+1]={0};
    // cout<<min_steps_bottom_up_dp(n)<<endl;
    // cout<<min_steps_top_down_dp(n,dp)<<endl;
     
    return 0;
}