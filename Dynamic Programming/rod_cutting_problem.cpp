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

//Recursive solution
ll rod_cut(ll n,ll prices[]){
    //base case
    if(n==0) return 0;

    //rec case
    ll ans=LLONG_MIN;
    f(i,0,n){
        ll cut=i+1;
        ll curr_ans=prices[i]+rod_cut(n-cut,prices);
        ans=max(ans,curr_ans);
    }   

    return ans;
}

//Dp Top-Down
ll rod_cut_top_down(ll n,ll prices[],ll dp[]){
    //base case
    if(n==0) return 0;

    //rec case
    //lookup
    if(dp[n]!=0) return dp[n];
    ll ans=LLONG_MIN;
    f(i,0,n){
        ll cut=i+1;
        ll curr_ans=prices[i]+rod_cut_top_down(n-cut,prices,dp);
        ans=max(ans,curr_ans);
    }

    return dp[n]=ans;
}

//Dp Bottom-Up
ll rod_cut_bottom_up(ll n,ll prices[],ll dp[]){
    dp[0]=0;
    f(i,1,n+1){
        ll ans=LLONG_MIN;
        f(j,0,i){
            ll cut=j+1;
            ll curr_ans=prices[j]+dp[i-cut];
            ans=max(ans,curr_ans);
        }
        dp[i]=ans;
    }
    return dp[n];
}


int main(){
 
    ll n;cin>>n;
    ll prices[n];
    f(i,0,n){
        cin>>prices[i];
    }
    //simple recursive soln
    // cout<<rod_cut(n,prices)<<endl;

    //DP soln
    ll dp[n+1]={0};
    // cout<<rod_cut_top_down(n,prices,dp)<<endl;
    // cout<<rod_cut_bottom_up(n,prices,dp)<<endl;

    return 0;
}