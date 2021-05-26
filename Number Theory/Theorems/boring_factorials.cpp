/*
    Ques: https://www.spoj.com/problems/DCEPC11B/

    Explanation: 
    ------------

    We want to find out (n!)%p, but the problem is that n<=10^9...so we cannot calculate the factorial of such a big number.
    - now if you notice when p<=n, then we know that p will lie in n!, which means (n!)%p=0.
    - the tricky case is when p>n.
    - there is a theorem called Wilson's Theorem which says that :-
        if n is a prime number then -> (n-1)!%n = -1 (here -1 represents n-1).
        now using this,
        (p-1)!%p = -1
        this can be written as => (p-1)! ≡ -1(mod p)
        (1*2*3....(n-1)*n*....(p-2)*(p-1)) ≡ -1(mod p)        [(p-1)! = (1*2*3....(n-1)*n*....(p-2)*(p-1))]

        n! *(n+1)*...(p-2)*(p-1) ≡ -1(mod p)
        n! = (-1/((n+1)*..(p-2)*(p-1)))(mod p)

    Now we cannnot take mod when term is in denominator, so we have to calculate modinverse of 
    ((n+1)*..(p-2)*(p-1))

    Now to calculate mod inverse we have many ways, one way is :-
    Using Fermet's Little Theorem -
    (a^p)%p=a
    this can be written as - 
    a^p ≡ a(mod p)
    a^(p-1) ≡ 1(mod p)     [divide by a]
    a^(p-2) ≡ a^-1(mod p)  [divide by a]    (a^-1 = a inverse) 

    So a inverse is equal to a^(p-2).

   Using this - 
   to calculate inverse of ((n+1)*..(p-2)*(p-1))), we will calculate each term's power (p-2) and multiply all in the end, this will give us the mod inverse of this whole term.

    n! = (-1/((n+1)^(p-2)*..(p-2)^(p-2)*(p-1)^(p-2)))(mod p)

    As abs(n-p)<=1000, so we can do this for each term using a for loop and it won't give a TLE.
    
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;

ll fast_modulo_exponentation(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return (ans%m);
}

ll solve(ll n,ll p){
    ll ans=-1;
    f(i,n+1,p){
        ll temp=fast_modulo_exponentation(i,p-2,p);
        ans=(ans*temp)%p;
    }

    return (ans+p);
}

int main(){
    w(t){
        ll n,p;
        cin>>n>>p;
        if(n>=p) cout<<0<<endl;
        else{
            cout<<solve(n,p)<<endl;
        }
    }
return 0;
}