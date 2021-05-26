/*
    Ques - https://codeforces.com/problemset/problem/26/A
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
bitset<10000000> b;
vector<int> primes;

ll sieve(ll n){
    ll p[n+1]={0};
    //what we are basically doing here is that,for every prime number we are increasing the count of multiples of it, and in the end we will check if a number has count==2, then that means it had 2 prime divisors.
    for(ll i=2;i<=n;i++){
        if(!p[i]){
            for(ll j=i;j<=n;j+=i){
                p[j]++;
            }
        }
    }
    ll ans=0;
    f(i,0,n+1){
        if(p[i]==2) ans++;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    cout<<sieve(n)<<endl;
}