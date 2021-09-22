/*
    Problem - https://hack.codingblocks.com/app/contests/1338/546/problem
*/

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
    this just gives 40 points
    if someone is able to figure out the top-down solution for this problem then please tell me too!
*/
ll minCost_topDown(ll n,ll x,ll y,ll z,ll c,ll dp[]){
    //base case
    if(c==n) return 0;

    //rec case
    //lookup
    if(dp[c]!=0) return dp[c];
    ll op1=minCost_topDown(n,x,y,z,c+1,dp)+y;
    ll op2=LLONG_MAX;
    if(2*c<=n){
        op2=minCost_topDown(n,x,y,z,2*c,dp)+x;
    }
    
    ll op3;
    if(n%2!=0){
        op3=dp[(n+1)/2]+x+z;
        return dp[c]=min({op1,op2,op3});
    }

    return dp[c]=min(op1,op2);
}

ll minCost_bottomUp(ll n,ll x,ll y,ll z,ll dp[]){
    //as we spend no cost to to reach these levels
    dp[0]=0,dp[1]=0;

    ll op1,op2;
    f(i,2,n+1){
        /*if i is even then we can reach it in 2 ways, either we can reach from i-1 by adding one,
          or we can reach from i/2 by doing i*2
        */
        if(i%2==0){
            op1=dp[i/2]+x;
            op2=dp[i-1]+y;
        }
        /*if i is odd then we can reach it in 2 ways, either we can reach from i-1 by adding one,
          or we can reach from (i+1)/2 by first doing i*2 and then subtracting one.
        */
        else{
            op1=dp[(i+1)/2]+x+z;  // +x for doubling, and +z fro subtracting one
            op2=dp[i-1]+y;
        }
        dp[i]=min(op1,op2);
    }

    return dp[n];

}

int main(){
    fast

    ll n;cin>>n;
    ll x,y,z;cin>>x>>y>>z;
    ll dp[n+1]={0};
    // cout<<minCost_topDown(n,x,y,z,1,dp)<<endl;
    cout<<minCost_bottomUp(n,x,y,z,dp)<<endl;
     
    return 0;
}