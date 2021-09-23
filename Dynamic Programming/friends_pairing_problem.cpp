#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
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


ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

/*
    f(n) = f(n-1)+ (n-1)C(1)*f(n-2)     (Because as the nth person can choose any one person from n-1 persons...So we multiply (n-1)C(1) with f(n-2) ....(nCr)) 

    Time Complexity - O(n)
    Space Complexity - O(n)

*/

ll friends_pairing_topDown(ll n){
    //base case
    if(n==0 || n==1) return 1;

    //rec case
    //lookup
    if(dp[n]!=0) return dp[n];
    ll op1=friends_pairing_topDown(n-1,dp);
    ll op2=friends_pairing_topDown(n-2,dp)*binomialCoeff(n-1,1);

    return dp[n]=op1+op2;

}

/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

ll friends_pairing_bottomUp(ll n,ll dp[]){
    //base case
    if(n<=2) return n;

    f(i,3,n+1){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    
    return dp[n];

} 

/*
    ** Space optimized **
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

ll friends_pairing_iterative(ll n){
    //base case
    if(n<=2) return n;

    ll a=1,b=2,c;
    f(i,3,n+1){
        c=b+(i-1)*a;    // (n-1)C(1) => n-1 
        a=b;
        b=c;
    }

    return c;

}

/* This will be interesting, complete it later :)
ll friends_pairing_mathApproach(){
    
}
*/

int main(){

    ll n;cin>>n;
    ll dp[n+1]={0};
    cout<<friends_pairing_topDown(n,dp)<<endl;

    return 0;
}

/*
    Yeh dil maange more :)
*/