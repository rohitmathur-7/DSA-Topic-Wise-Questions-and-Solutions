/*
    Mobius Function :-
    ----------------
    For any positive integer n, define μ(n) as the sum of the primitive nth roots of unity. It has values in {−1, 0, 1} depending on the factorization of n into prime factors:

    - μ(n) = 1 if n is a square-free positive integer with an even number of prime factors.
    - μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
    - μ(n) = 0 if n has a squared prime factor.


    Logic :-
    ------

    -First we will make an array of size N(num[N]) with all elements 1.

    -Now we will iterate from 2 to N, and if the current number is prime then we will multiply all its multiples with the current prime number.Ex: if current prime is 2, then at 4 it will be 1*2=2, at 6 it will be 1*2=2... and so on.And also we will make a prime_count array which will store that how many primes divide the number at that index.

    -Now first of all what is square free number -
    In mathematics, a square-free integer (or squarefree integer) is an integer which is divisible by no perfect square other than 1. That is, its prime factorization has exactly one factor for each prime that appears in it. For example, 10 = 2 ⋅ 5 is square-free, but 18 = 2 ⋅ 3 ⋅ 3 is not, because 18 is divisible by 9 = 32.

    -So now after all this, if a number at index num[i] is equal to i..then that means that the number is a square free number, so now if it has even number of prime divisors,then its mobius value will be 1, otherwise it will be -1.
    
    -And if num[i]!=i, then that means this number is not a squarefree number,
    So its mobius value will be 0.

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
const ll N = 100005;
ll num[N],prime_count[N],mobius[N];

void mobius_function(){

    f(i,1,N){
        num[i]=1;
    }
    f(i,2,N+1){
        if(prime_count[i]) continue;
        for(ll j=i;j<=N;j+=i){
            prime_count[j]++;
            num[j]*=i;
        }
    }

    f(i,1,N){
        if(num[i]==i){
            if(prime_count[i]%2!=0) mobius[i]=-1;
            else mobius[i]=1;
        }
        else mobius[i]=0;
    }

    return;
}


int main(){
    ll n;
    cin>>n;
    mobius_function();
    f(i,1,n+1){
        cout<<mobius[i]<<" ";
    }
    return 0;
}