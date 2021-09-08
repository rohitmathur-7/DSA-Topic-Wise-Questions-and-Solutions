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
                     
//************************
//Important functions
                      
//gcd
/*
ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}
*/
                        
//extended euclid algorithm
/*
void extendedEuclidAlgorithm(ll a,ll b){
    //base case
    if(b==0){
        x=1;y=0;
        GCD=a;
        return;
    }
    //rec case
    extendedEuclidAlgorithm(b,a%b);
    ll cx=y;
    ll cy=x-((a/b)*y);
                    
    x=cx;
    y=cy;
}
*/
                        
//to compute a^b
/*
ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
*/
 
//to find multiplicative modulo inverse
/*
void multiplicative_modulo_inverse(ll a,ll m){
    if(gcd(a,m)==1){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        cout<<(x+m)%m<<endl;
    }
    else cout<<
Multiplicative modulo inverse is not possible!
<<endl;
}
*/
 
//prime sieve
/*
void prime_sieve(ll *p){
    for(ll i=3;i<=100000;i+=2) p[i]=1;
 
    for(ll i=3;i<=100000;i+=2){
    if(p[i]==1){
        for(ll j=i*i;j<=100000;j+=i){
            p[j]=0;
        }
        }
        }
    p[2]=1;
    p[1]=0;p[0]=0;
}
*/
//************************

/*
    T.C = O(N*X)
    S.C = O(X)
*/
ll coin_chng_top_down_dp(ll n,ll x,ll dp[],ll coins[]){
    //base case
    if(x==0) return 0;
    
    //rec case
    if(dp[x]!=0) return dp[x];
    ll ans=LLONG_MAX;
    f(i,0,n){
        if(x-coins[i]>=0){
            ans=min(ans,coin_chng_top_down_dp(n,x-coins[i],dp,coins)+1);
        }
    }
    dp[x]=ans;
    return ans;
}

ll coin_chng_bottom_up_dp(ll n,ll x,ll coins[],ll dp[]){
    dp[0]=0;
    //iterate over all states from 1 to X
    f(i,1,x+1){
        //initialize currebt ans as LLONG_MAX
        ll ans=LLONG_MAX;
        f(j,0,n){
            if(i-coins[j]>=0){
                ans=min(ans,dp[i-coins[j]]+1);
            }
        }
        dp[i]=ans;
    }

    return dp[x];
}

int main(){
    /*
        n -> size of coins array
        x -> the amount for which we want to find the answer
    */
    ll n,x;cin>>n>>x;
    ll coins[n];
    f(i,0,n){
        cin>>coins[i];
    }
    ll dp[x+1]={0};
    // cout<<coin_chng_top_down_dp(n,x,dp,coins)<<endl;
    cout<<coin_chng_bottom_up_dp(n,x,coins,dp)<<endl;
     
    return 0;
}