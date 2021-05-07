/*
    Ques: https://www.spoj.com/problems/PRIME1/
*/

/*
    We will use segmented sieve in this question.
    The reason we cannot use our prime sieve is that n,m<=10^9 and our prime sieve array can only be as large as 10^7, so we will not be able to directly check if a number if prime or not.
    And also we are given onw thing that is, n-m<=10^5
    So we will take advantage of this thing, and the basic idea here is that...
    We will create a shifted array,
     i.e if m=50,n=100 then we will create a array of size n-m+1 and the 0th index will represent m and (n-m)th index will represent n, and any index i in between will represent i-m.
     We are doing this bcz we know that n,m<=10^9 so we can't directly work on them, so we are creating a shifted array(we call it segment) and as n-m<=10^5 so it will work.

    Now what we will do is, we will iterate over our prime array, and first find the starting point
    ex: if m=99 and n=144 then starting point when prime number=2 will be = (99/2)*2 =>98
    now if this number < m, then add that prime number to it again.

    Now we will iterate from start to n,and we will mark the multiples of that prime number as false, so that we know that the number being marked is not a prime.
    
    And in the end we will iterate from m to n,and the number which are not marked are prime numbers...So we will print them.

*/




#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
const ll N = 100000;
vector<ll> prime;
ll p[N]={0};

void sieve(){
    for(ll i=2;i<=N;i++){
        if(!p[i]){
            prime.push_back(i);
            for(ll j=i;j<=N;j+=i){
                p[j]=1;
            }
        }
    }
}

int main(){
    sieve();
    w(t){
        ll n,m;
        cin>>m>>n;
        bool segment[n-m+1];
        memset(segment,false,sizeof(segment));
        for(auto x:prime){
            //we only need to iterate till sqrt(n).
            if(x*x>n) break;
            //calculating the starting number from where we have to mark numbers.
            ll start=(m/x)*x;
            /* if the number exits in prime array and also in segment array, then we will do this otherwise it will give start as 0. ex: m=5 and x=7, now start=(5/7)*7 => 0
            So that is why we will make start as 7*2 =>14.
            */
            if(x>=m && x<=n) start=2*x;
            for(ll i=start;i<=n;i+=x){
                if(i-m>=0) segment[i-m]=1;
            }
        }

        //the numbers which are not marked are prime, we just print them here
        for(ll i=m;i<=n;i++){
            if(segment[i-m]==0 && i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}