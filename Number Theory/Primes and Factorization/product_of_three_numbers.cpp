/*
    Ques - https://codeforces.com/problemset/problem/1294/C


    Approach - 
    -Do prime factorization of n
    -if there is only 1factor, and its power>5 ....then ans would be YES else NO.
        Suppose for a number we got its only prime factor as 2, then - 
        for us to have atleast 3 distinct numbers we need, 2, 2^2, 2^3 which tells us that the power>5.
    -if we have 2 factors then, if count of power>4, then ans is YES else NO.
    -if we have>2 factors, then ans is always YES.

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vec vector<ll>
#define vp vector< pair<ll,ll> >
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
    ll p[100005]={0};
    sieve(p);
    w(t){
        ll n;
        cin>>n;
        ll nn=n;
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

        count=0;
        for(auto x:factors){
            count+=x.second;
        }
        ll sze=factors.size();
        ll a1=1,a2=1,a3=1;
        if(sze==1){
            if(count>5){
                cout<<"YES"<<endl;
                a1=factors[0].first;
                a2=a1*a1;
                a3=pow(a1,(factors[0].second-3));
                cout<<a1<<" "<<a2<<" "<<a3<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            if(sze==2){
                if(count>=4){
                    cout<<"YES"<<endl;
                    a1=factors[0].first;
                    a2=factors[1].first;
                    ll d=a1*a2;
                    a3=nn/d;
                    cout<<a1<<" "<<a2<<" "<<a3<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
                ll cnt=0;
                for(auto x:factors){
                    if(cnt==0){
                        a1=pow(x.first,x.second);
                    }
                    else if(cnt==1){
                        a2=pow(x.first,x.second);
                    }
                    else{
                        a3*=pow(x.first,x.second);
                    }
                    cnt++;
                }
                cout<<a1<<" "<<a2<<" "<<a3<<endl;
            }
        }
    }
    return 0;
}