/*
    Ques - A Factorial Problem
    Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.

    Input Format
    First line contains number of test cases, T. Each test case contains two integers each, n and k.

    Constraints
    1<=T<=20 1<=n<=10^8 2<=k<=10^8

    Output Format
    Print the value of x for each test case.

    Sample Input
    2
    5 2
    1000 2
    Sample Output
    3
    994
    Explanation
    In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120. So, the answer should be 3.
*/


#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
vector<ll> primes;

void sieve(ll *p){
    p[0]=p[1]=0;
    p[2]=1;
    primes.push_back(2);
    for(ll i=3;i<=100000;i+=2){
        p[i]=1;
    }
    for(ll i=3;i<=100000;i+=2){
        if(p[i]){
            primes.push_back(i);
            for(ll j=i;j<=100000;j+=i){
                p[j]=0;
            }
        }
    }
}

ll fact(ll n){
	if(n<=1) return 1;
	return n*fact(n-1);
}

int main(){
    ll p[100005]={0};
    sieve(p);
    w(t){
        ll n,k;
        cin>>n>>k;

    /*
        step 1 - prime factorize k , and from that find k1,k2,k3..kl
        step 2 - prime factorize n, and then from the prime factors take out c1,c2,....cl from the formula - n/p1+n/p1^2..
        step 3 - find the min, x=min(c1/k1,c2/k2,....cl/kl), x is our ans.
    */

   //step 1 - prime fact k.
        vector< pair<ll,ll> > factors1;
        ll count=0;
        for(ll i=0;i<primes.size();i++){
            ll x=primes[i];
            if(x*x>k) break;
            if(k%x==0){
                count=0;
                while(k%x==0){
                    k/=x;
                    count++;
                }
                factors1.push_back(make_pair(x,count));
            }
        }
        if(k!=1) factors1.push_back(make_pair(k,1));
    
    //step 2 - prime fact n.
        vector< pair<ll,ll> > factors2;
        count=0;
        ll nn=n;
        for(ll i=0;i<primes.size();i++){
            ll x=primes[i];
            if(x*x>n) break;
            if(n%x==0){
                count=0;
                while(n%x==0){
                    n/=x;
                    count++;
                }
                factors2.push_back(make_pair(x,count));
            }
        }
        if(n!=1) factors2.push_back(make_pair(n,1));
    //finding c1,c2...cl
        ll temp;
        vector<ll> cl;
        for(auto x:factors1){
            ll c=x.first;ll a=0;
            temp=nn;
            bool g=true;
            while(g){
                if(c>temp) break;
                a+=(nn/c);
                c*=x.first;
            }
            cl.push_back(a);
        }

        sort(factors1.begin(),factors1.end());
        sort(cl.begin(),cl.end(),greater<ll>());

        //Step 3 - finding the minimum
        vector<ll> v;
        for(ll i=0;i<factors1.size();i++){
            ll one = cl[i];
            ll two = factors1[i].second;
            v.push_back(one/two);
        }

        ll ans=*min_element(v.begin(),v.end());
        cout<<ans<<endl;
    }

    return 0;
}