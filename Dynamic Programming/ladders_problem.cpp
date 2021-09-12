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
    Time Complexity -> O(n*k)
    Space Complexity -> O(n)
*/

//T.C - O(n*k)
ll ladder_top_down(ll n,ll k,ll dp[]){

    //base case
    //we are at ground, and there is just one way to stand on the ground.
    if(n==0) return 1;

    //rec case
    //lookup
    if(dp[n]!=0) return dp[n];
    //f(n)=f(n-1)+f(n-2)+....f(n-k)
    ll ways=0; 
    //iterating over the last k elements from n
    f(i,1,k+1){
        //n-i cannot be -ve obviously, bcz if we have to reach n=4, then we cannot jump to 5.
        if(n-i>=0){
            ways+=ladder_top_down(n-i,k,dp);
        }
    }

    return dp[n]=ways;
}

//T.C - O(n*k)
ll ladder_bottom_up(ll n,ll k,ll dp[]){

    dp[0]=1;
    //iterating over all values till n
    f(i,1,n+1){
        //iterating over the last k elements from i
        for(ll j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }

    //printing the dp array to see what values each element from 0 to n holds
    // f(i,0,n+1){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    return dp[n];
}

/*
    T.C -> O(n+k)
    
    Explanation:
    -----------
    We know that dp[n]=dp[n-1]+dp[n-2]+....dp[n-k];

    Now if we look at our dp array it is -> 1 1 2 4 7 13 24......

    dp[6]=24 =>(4+7+13)

    so dp[7]=dp[6]+dp[5]+dp[4] => (7+13+24)
    So if we see dp[n+1]=dp[n]+dp[n-1]+dp[n-2]
    and we calculated dp[n] using dp[n-1],dp[n-2] and dp[n-3],
    so for dp[n+1] we are just removing dp[n-3].

    So we can write dp[n+1] as => dp[n]+dp[n]-dp[n-k]  (It is kind of like sliding window)

    4 7 13 => 24  (4+7+13)
    ------

    4 7 13 24 => 44 (7+13+24)
      -------

    So what we will do is for elements till k our dp[i]=2*dp[i-1]+dp[i-k-1]
    but dp[i-k-1] will be 0 or -ve. So we will do dp[i]=2*dp[i-1]
    and for rest of the elements dp[i]=2*dp[i-1]+dp[i-k-1].

*/
ll ladders_bottom_up_optimized(ll n,ll k,ll dp[]){
    dp[0]=dp[1]=1;
    
    f(i,2,k+1){ 
        dp[i]=2*dp[i-1];
    }   
    f(i,k+1,n+1){
        dp[i]=(2*dp[i-1])-dp[i-k-1];
    }
    //printing the dp array to see what values each element from 0 to n holds
    // f(i,0,n+1){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    return dp[n];    
}

int main(){
    
    //n -> the step where we need to reach, k -> the maximum jump that we can take
    ll n,k;
    cin>>n>>k;
    ll dp[n+1]={0};
    // cout<<ladder_top_down(n,k,dp)<<endl;
    // cout<<ladder_bottom_up(n,k,dp)<<endl;
    cout<<ladders_bottom_up_optimized(n,k,dp)<<endl;

    return 0;
}