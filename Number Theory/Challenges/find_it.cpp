/*
    Ques: 
    You are given N numbers.
    Now you have Q queries.
    For each query you will be given an integer K.
    You have to find out the number of multiples of K among the given N numbers.

    Input Format
    The first line consists of number N.
    Next N line contains N numbers. Next line contains number of queries Q. Next Q lines contains Integer K for each query

    Constraints
    1 <= N <= 10^5 1 <= numbers <= 10^5 1 <= Q <= 10^5 1 <= K <= 10^5

    Output Format
    Output Q lines the answer for every query.

    Sample Input
    4
    5
    8
    10
    8
    1
    2
    Sample Output
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
#define mod 1000000007
using namespace std;
vl primes;
map<ll,ll> sum,m;

void sieve(){
    f(i,1,100001){
        for(ll j=i;j<=100000;j+=i){
            sum[i]+=m[j];
        }
    }
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    f(i,0,n){
        cin>>arr[i];
        m[arr[i]]++;
    }
    sieve();
    ll q;
    cin>>q;
    f(i,0,q){
        ll x;
        cin>>x;
        cout<<sum[x]<<endl;
    }
     
    return 0;
}