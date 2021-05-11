/*
    Ques: given 2 numbers,find gcd of them.
*/


//Time Complexity - O(log(n))
#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;

ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}

int main(){
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;;
}