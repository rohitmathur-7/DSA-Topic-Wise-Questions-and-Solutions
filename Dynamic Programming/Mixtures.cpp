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

// a1 a2 a3 a4 a5

// mix -> ta1(new color) = (a1+a2)%100
//         smoke generated = a1*a2

        
ll dp[101][101];    

ll sum(ll s,ll e,ll arr[]){

    ll ss=0;
    f(i,s,e+1){
        ss+=arr[i];
        ss%=100;
    }

    return ss;

}

/*
    ** This problem is a variation of Matrix Chain Multiplication Problem **
    Explanation - 
    What we will do is break the problem into subparts,
    i.e if we are given A B C D mixtures, then we will break it like this ->
            (A)(B C D), (A B)(C D), (A B C)(D)
            and then these will be further broken down just like we did above.
            For ex (A)(B C D) will be broken like this ->
            (A)(B C D)
                        (B C D) -> (B)(C D), (B C)(D) 
            And it will go on like this.
            So here we can see that there will be many overlapping sub-problems,
            so here we will use a Dp array to store the answer's to sub-problems and use them later.

    Time Complexity - O(n^3)
    Space Complexity - O(n^2)

*/

ll mixtures_topDown(ll s,ll e,ll arr[]){

    //base case
    //this means that we are not combining any mixtures, so smoke produced is 0.
    if(s>=e) return 0;

    //rec case
    //lookup
    if(dp[s][e]!=-1) return dp[s][e];

    dp[s][e]=LLONG_MAX;
    /*
        mixtures(s,k,arr)+mixtures(k+1,e,arr)+sum(s,k,arr)*sum(k+1,e,arr) this thing denotes that,
        we have the answer to the subproblems mixtures(s,k,arr) and mixtures(k+1,e,arr) using recursion, here answer is the amount of smoke produced, so (mixtures(s,k,arr)+mixtures(k+1,e,arr)) this is for that...
        and (sum(s,k,arr)*sum(k+1,e,arr)) this is for the amount of smoke produced when mixtures from (s to k) and from (k+1 to e) are mixed together.(Smoke produced by mixing 2 mixtures A and B is (A+B)%100, so suppose we have mixtures int the range s to k and from k+1 to e....So Smoke produces when we mix these 2 mixtures from range (s to k) and (k+1 to e) will be => (arr[s]+arr[s+1]+....arr[k])*(arr[k+1]+arr[k+2]...arr[e]).
        So sum function just calculates the summision from range (s to k) and from (k+1 to e).(And taking mod while doing the summision).

    */
    f(k,s,e+1){
        dp[s][e]=min(dp[s][e],mixtures_topDown(s,k,arr)+mixtures_topDown(k+1,e,arr)+sum(s,k,arr)*sum(k+1,e,arr));
    }

    return dp[s][e];     
    
}

/*  Write this as soon as possible!
ll mixtures_bottomUp(){
    
}
*/
 
int main(){
    fast
    ll n;
    while(cin>>n){
        ll arr[n];
        f(i,0,n){
            cin>>arr[i];
        }
        f(i,0,101){
            f(j,0,101){
                dp[i][j]=-1;
            }
        }
        cout<<mixtures_topDown(0,n-1,arr)<<endl;
    }
     
    return 0;
}