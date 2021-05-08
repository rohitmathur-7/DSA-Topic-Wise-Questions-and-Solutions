//Ques - Count the number of divisors of a given number.

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
vector<ll> primes;


void sieve(ll *p){
    p[0]=0,p[1]=0,p[2]=1;
    
    primes.push_back(2);
    //assuming all odd numbers as prime
    for(ll i=3;i<=100000;i+=2){
        p[i]=1;
    }
    for(ll i=3;i<=100000;i+=2){
        if(p[i]==1){
            primes.push_back(i);
            for(ll j=i;j<=100000;j+=i){
                p[j]=0;
            }
        }
    }

}

int main(){
    ll n;
    cin>>n;
    ll p[100005]={0};
    sieve(p);

    ll count=0;
    ll ans=1;
    for(ll i=0;primes[i]*primes[i]<=n;i++){
        ll x=primes[i];
        if(n%x==0){
            count=0;
            while(n%x==0){
                n/=x;
                count++;
            }
            ans=ans*(count+1);
        }
    }

    if(n!=1) ans*=2;
    cout<<ans<<endl;

    return 0;
}


