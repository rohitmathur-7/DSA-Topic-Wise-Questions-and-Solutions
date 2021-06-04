/*
    Ques: 
    Virat is learning to calculate nCr. Dhoni gave him some n and r values to solve for nCr. As the result can be large, he asked him to print (nCr % 1000000007).

    Input Format
    Single line containing two integers 'n' and 'r'.

    Constraints
    1<=n,r<=1000000 1<=r<=n

    Output Format
    Print the required output.

    Sample Input
    3 2
    Sample Output
    3

    Explanation:

    nCr = (n!)/(n-r)!*(r)!

    nCr = (n!) * inverseOf(n-r)! * inverseOf(r)!

    Taking mod both sides -
    (nCr)%mod = ((n!) * inverseOf(n-r)! * inverseOf(r)!)%mod

    As mod has distributive property - 
    (nCr)%mod = ((n!) % mod) * (inverseOf(n-r)! % mod) * (inverseOf(r)! % mod)
    
    Now we can also distribute mod in n! as-
    n! = 1%mod * 2%mod * 3%mod........* (n-1)%mod * n%mod

    Now to calculate (inverseOf(n-r)! % mod) & (inverseOf(r)! % mod) -

    By Fermat's Little Theorem -
    (a^p) % p = a

    a^(p-1) % p = 1
    a^(p-2) % p = a^-1(a inverse)
    
    so inverse of a = a^(p-2) % p 

    so in our case inverse of r! = (r!)^(mod-2) % mod
    and inverse of (n-r)! = (n-r)!^(mod-2) % mod

    And our answer = ((n!) % mod) * (inverseOf(n-r)! % mod) * (inverseOf(r)! % mod)

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
ll arr[1000001];

ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans%mod;
}

int main(){
    ll n,r;
    cin>>n>>r;
    arr[0]=arr[1]=1;
    ll ans;

    f(i,2,n+1){
        arr[i]=(arr[i-1]*i)%mod;
    }
    ans=arr[n];

    ans=(ans*fast_modulo_exponentation(arr[r],mod-2))%mod;
    ans=(ans*fast_modulo_exponentation(arr[n-r],mod-2))%mod;

    cout<<ans<<endl;

    return 0;
}