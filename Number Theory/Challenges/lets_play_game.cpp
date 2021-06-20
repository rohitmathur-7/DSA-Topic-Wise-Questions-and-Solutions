/*
    Ques: 
    Alice is fond of playing mathematical games. This time he comes up with a unique game. He takes a number 'N' and calls magic fraction of N as:

    It is a proper fraction (The value is < 1)
    It cannot be reduced further
    The product of the numerator and the denominator is factorial of N. i.e. if a/b is the fraction, then a*b = N!
    For example magic fractions for 3 are 2/3 and 1/6.

    Now given a number N, you need to print the total number of magic fractions that exist, for all numbers from 1 till N (both inclusive).
    Input Format
    Single line containing integral value 'N'.

    Constraints
    1<=N<=500

    Output Format
    Print integral value denoting total number of magic fractions.

    Sample Input
    3
    Sample Output
    3
    Explanation
    0 for 1 + 1 for 2 (1/2) + 2 for 3 (1/6, 2/3)=3
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
#define N 100005
using namespace std;
        
//to compute a^b
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
 
//prime sieve
void prime_sieve(ll *p){
    for(long long i=3;i<=100000;i+=2) p[i]=1;

    for(long long i=3;i<=100000;i+=2){
        if(p[i]==1){
            for(long long j=i*i;j<=100000;j+=i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=0;p[0]=0;
}

int main(){

    ll p[100005]={0};
    prime_sieve(p);
    ll n;
    cin>>n;
    ll k=0;
    ll ans=1;

    if(n==1) cout<<0<<endl;
    else{
        f(i,3,n+1){
            if(p[i]) k++;
            ans+=fast_modulo_exponentation(2,k);
        }
        cout<<ans<<endl;
    }

    return 0;
}