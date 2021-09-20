
/*
    Problem - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
*/

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
    Time Complexity - O(n^3)
    Space Complexity - O(n^2)
*/

ll matrixMultiplication(ll n,ll *arr){  
    ll dp[200][200];
    memset(dp,0,sizeof(dp));
    n--;//as n was equal to number of matrices+1
    f(i,1,n){  //iterating over columns
        ll r=0,c=i; //starting from 0th row and ith column
        while(c<n){
            ll val=LLONG_MAX;
            //so here what we are basically doing is that, we are finding the minimum cost for multiplying matrices from range r to c.
            f(pivot,r,c){   //this is the point which will vary and its range will be -> [r,c-1]
                ll d=arr[r]*arr[pivot+1]*arr[c+1];
                val=min(val,dp[r][pivot]+dp[pivot+1][c]+d);
            }
            dp[r][c]=val;
            r++,c++;//as we are calculating ans diagonally bcz in that the diff b/w r and c remains the same.
        }
    }

    return dp[0][n-1]; //dp[0][n-1] will store our ans, as it means we are asking the program to give the minimum cost of multiplying the matrices from range 0 to n-1.

}


int main(){
    ll n;cin>>n; //number of dimensions required   (n = number of matrices+1)
    ll arr[n];   //dimensions of the matrices
    f(i,0,n){
        cin>>arr[i];
    }

    cout<<matrixMultiplication(n,arr)<<endl;

    return 0;
}