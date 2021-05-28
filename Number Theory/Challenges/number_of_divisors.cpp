/*  
    Ques:
    Little Bob and Mary once got into a fight over rating on codeforces. Bob asked Mary to share her ice-cream with him if she couldn't answer the question. Mary agreed as she was so confident of herself. Bob asked you are given a number n find its number of divisors. Mary answered it in a flash and started laughing. Bob said the question isn't over yet. Since n can be as large as having 50 digits you are only given some numbers <= 1000000 whose product is n. Mary got a bit surprised and started working on the question. Now you have to help Mary find the number of divisors of (a1* a2* a3 ….an) where you are given a1 a2 a3.. an. Since the answer can be large output it modulo 10^9+7.

    Input Format
    first line consist of number of test cases. First line of every text case consists of integer n. the second line consists of n integers.

    Constraints
    1 <= n <= 15 1 <= ai <= 1000000 1 <= test cases <= 10

    Output Format
    the number of divisors modulo 10^9 + 7.

    Sample Input
    3
    3
    13 50 70
    3
    22 41 60
    2
    5 5

    Sample Output
    48
    64
    3
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair()
#define mod 1000000007
using namespace std;
vl primes;
map<ll,ll> m;

void numberOfDivisors(ll n){

    ll div=1;
    f(i,0,primes.size()){
        ll x=primes[i];
        if(x*x>n) break;
        if(n%x==0){
            ll cnt=0;
            while(n%x==0){
                n/=x;
                cnt++;
            }
            m[x]+=cnt;
            div*=(cnt+1);
        }
    }

    if(n!=1){
        div*=2;
        m[n]+=1;
    }

}

void sieve(ll *p){
    p[0]=p[1]=0;

    for(ll i=3;i<=100000;i+=2) p[i]=1;
    primes.pb(2);
    f(i,3,100001){
        if(p[i]){
            primes.pb(i);
            for(ll j=i;j<=100000;j+=i){
                p[i]=0;
            }
        }
    }

}
                     
int main(){
    ll p[100001]={0};
    sieve(p);
    w(t){
        ll n;
        cin>>n;
        ll arr[n];
        f(i,0,n){
            cin>>arr[i];
        }

        ll ans=1;
        f(i,0,n){
            numberOfDivisors(arr[i]);
        }

        for(auto x:m){
            ans*=(x.second+1);
        }

        cout<<ans<<endl;
        m.clear();
    }
  
    return 0;
}