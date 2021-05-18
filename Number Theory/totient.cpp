/*
    Euler Phi Function or Totient(Φ) -
    --------------------------------

    This function basically gives the number of numbers co-prime with our given number n which are less than n.
    [Co-prime - When 2 numbers have their GCD as 1.]

    Ex: Φ(8) = [1,3,5,7] = 4 (Every number in the bracket is < 8, and has GCD as 1 with 8)
        Φ(9) = [1,2,4,5,7,8] = 6

    We can calculate totient of a number(Φ) with a simple formula - 

    Φ(n) = n*[1-(1/p1)]*[1-(1/p2)]*[1-(1/p3)]*.......*[1-(1/pk)]
                                            (here p1,p2...pk denotes the prime factors of the number n.)

    Ex: Calculate Φ(25)
        25 = 5*5
        5 is the only prime factor of 25.
        Φ(25) = 25*[1-(1/5)] = 20

    The intution behind this formula is that, what we are doing is, we are subtracting the number of multiples of a prime factor from that number bcz those multiples can never be co-prime with n.
     Ex - multiple of 5 = 10, gcd(10,25)=5, but if you take any other number than a multiple of 5 till 25, then the gcd will always be 1 with that number and n.                                           

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll> 
#define  vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;

void sieve(ll *p){
    f(i,2,100005){
        for(ll j=i;j<=100005;j+=i){
            if(p[j]==0) p[j]=i;
        }
    }    
}

int main(){
    ll p[100005]={0};
    sieve(p);
    ll n;
    cin>>n;
    ll ans=1;

    vl factors;
    ll x,y,nn=n;
    
    x=n;
    while(n>1){
        n/=p[x];
        x=p[n];
        if(find(factors.begin(),factors.end(),x)==factors.end() && n==x){
            factors.pb(x);
        }
    }

    ll cnt=0;
    for(auto x:factors){
        if(cnt==0) ans=nn-(nn/x);
        else ans*=(1-(1/x));
        cnt++;
    }
    cout<<ans<<endl;

    return 0;
}















