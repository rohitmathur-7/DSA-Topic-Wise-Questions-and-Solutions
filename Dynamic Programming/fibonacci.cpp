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
Calculating fibonacci number using normal recursion. 
        T.C - O(2^N) (Exponential)
        S.C - O(N) (linear)
*/
ll fibonacci_using_normal_recursion(ll n){
    //base case
    if(n==0 || n==1) return n;

    //rec case
    ll ans;
    ans=fibonacci_using_normal_recursion(n-1)+fibonacci_using_normal_recursion(n-2);
    return ans;
}

/*
Calculating fibonacci number using Top-Down DP.  
        T.C - O(N) (linear)
        S.C - O(N) (linear)
*/
ll fibonacci_using_Top_Down_DP(ll n,ll dp[]){
    //base case
    if(n==0 || n==1) return n;
    
    //rec case
    //if the subproblem is already calculated, then just return its value
    if(dp[n]!=0) return dp[n];
    ll ans;
    ans=fibonacci_using_Top_Down_DP(n-1,dp)+fibonacci_using_Top_Down_DP(n-2,dp);
    //assigning value of fib(n) to dp[n] to use it later.(Memoization)
    return dp[n]=ans;
}

/*
Calculating fibonacci number using Bottom-Up DP.  
        T.C - O(N) (linear)
        S.C - O(N) (linear)
*/
ll fibonacci_using_Bottom_Up_DP(ll n,ll dp[]){
    dp[0]=0,dp[1]=1;
    f(i,2,n+1){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

/*
Calculating fibonacci number using Bottom-Up DP(Space Optimized Version).  
        T.C - O(N) (linear)
        S.C - O(1) (constant)
The idea is that instead of using the whole array we will just use 2 variables to store the previous 2 value, as those are the only values that matters to us to calculate the nth fibonacci number.
*/
ll fibonacci_using_Bottom_Up_DP_Space_Optimized(ll n){
    //base case
    if(n==0 || n==1) return n;

    ll a=0,b=1,c;
    f(i,2,n+1){
        c=a+b;
        a=b,b=c;
    }
    return c;
}

int main(){
    
    ll n;cin>>n;

    //** Normal Recursion **
    // cout<<fibonacci_using_normal_recursion(n)<<endl;


    //** Dp approaches **
    // ll dp[100]={0};
    // cout<<fibonacci_using_Top_Down_DP(n,dp)<<endl;
    // cout<<fibonacci_using_Bottom_Up_DP(n,dp)<<endl;
    // cout<<fibonacci_using_Bottom_Up_DP_Space_Optimized(n)<<endl;

    return 0;
}