#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
vector<ll> primes;


//METHOD 1 - NAIVE APPROACH
// //this is the naive approach, and it will take O(n) time.
void prime_factors_naive_approach(ll n){
    ll count;
    vector< pair<ll,ll> > factors;

    //iterate from 2 to n, and if any i divides n, then keep on dividing n with i until it is not fully divided by i, and keep a count while doing this so that we will know the number of times i will occur in prime factorization of n.
    f(i,2,n+1){
        if(n%i==0){
            count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            factors.push_back(make_pair(i,count));
        }
    }

    // we are doing this bcz, suppose n=66, now first 2 will divide it and n=33, now 3 will divide it and n=11...and as we are only iterating till sqrt(n) and as n is changing at each step, as now n=11, but sqrt(11)=3.3(approx)...so as soon as we i will be 4, the loop will break.So what this means is that, we could not find a prime factor of n in the range 2 to sqrt(n)..which means that the number left is a prime number.So we will just push the left prime number in the vector.
    if(n!=1) factors.push_back(make_pair(n,1));
    for(auto x:factors){
        cout<<x.first<<"^"<<x.second<<endl;
    }
    cout<<endl;
}


//METHOD 2 - OPTIMIZED APPROACH
// //this is the optimized approach, and it will take O(sqrt(n)) time.
void prime_factors_optimized_approach(ll n){
    ll count;
    vector< pair<ll,ll> > factors;

    /*
    iterate from 2 to sqrt(n)...We are iterating only till sqrt(n) bcz there is a property, for a number n(which is not prime) there is always going to be at least 1 prime factor in the range 2 to sqrt(n), 
    and then in the loop if any i divides n, then keep on dividing n with i until it is not fully divided by i, and keep a count while doing this so that we will know the number of times i will occur in prime factorization of n.
    */
    f(i,2,sqrt(n)+1){
        if(n%i==0){
            count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            factors.push_back(make_pair(i,count));
        }
    }
    if(n!=1) factors.push_back(make_pair(n,1));
    for(auto x:factors){
        cout<<x.first<<"^"<<x.second<<endl;
    }
    cout<<endl;
}


//METHOD 3 - PRIME SIEVE APPROACH
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

    f(i,0,10) cout<<primes[i]<<" ";
    cout<<endl;
}

void prime_factors_sieve_approach(ll n){
    vector< pair<ll,ll> > factors;
    ll count=0;
    for(ll i=0;i<primes.size();i++){
        ll x=primes[i];
        if(x*x>n) break;
        if(n%x==0){
            count=0;
            while(n%x==0){
                n/=x;
                count++;
            }
            factors.push_back(make_pair(x,count));
        }
    }
    if(n!=1) factors.push_back(make_pair(n,1));

    for(auto x:factors){
        cout<<x.first<<"^"<<x.second<<endl;
    }
    cout<<endl;
}



int main(){
    ll n;
    cin>>n;

    //METHOD 1 - Naive approach
    // prime_factors_naive_approach(n);

    //METHOD 2 - Optimized approach
    // prime_factors_optimized_approach(n);

    //METHOD 3 - Prime Sieve
    // ll p[100005]={0};
    // sieve(p);
    // prime_factors_sieve_approach(n);

    return 0;
}