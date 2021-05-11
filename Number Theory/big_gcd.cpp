/*
    Ques: Calculate GCD of n,m where n<=10^7 and m<=10^250

    Approach :-
    First take n as int or long long, but take m as a string bcz obviously we cannot store that big of a   number in any data type.
    Now as we know from Euclid's Algorithm - GCD(A,B) = GCD(B,A%B)
    So what we will do is, we will try to reduce our number m by taking modulo with n.
    Now as m is large so we cannot directlt achieve this,
    So what we will do is this - 
    Suppose m is 12123, now we can write it as :-
    num = 1*10^4 + 2*10^3 + 1*10^2 + 2*10^1 + 3*10^0
    Now as we know modulo is distributive property, so we will do this - 
    num = (1%n*10^4%n)%n + (2%n*10^3%n)%n + (1%n*10^2%n)%n + (2%n*10^1%n)%n + (3%n*10^0%n)%n

    This way we will be able to reduce our m to a range of (0 <= m <n).
    Now we will just calculate the gcd of n and this new m.

*/


#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;

ll fast_modulo_exponentation(ll a,ll b,ll n){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=(a%n);
        }
        a*=(a%n);
        b>>=1;
    }
    return ans;
}

ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}

int main(){
    ll n;
    cin>>n;
    string m;
    cin>>m;
    if(n==0) cout<<m<<endl;
    else if(m=="0") cout<<n<<endl;
    else{
        ll sze=m.size();
        ll num=0,q,b;
        f(i,0,sze){
            q=m[i]-'0';
            b=sze-i-2;
            num+=((q)%n*(fast_modulo_exponentation(10,b+1,n))%n)%n; //use this  
            // num=(((num)%n*(10)%n)%n+(q)%n)%n; //or this
        }
        cout<<gcd(n,num)<<endl;
    }
}