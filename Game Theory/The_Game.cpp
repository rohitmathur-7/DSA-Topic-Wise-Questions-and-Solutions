/*
    Ques: https://www.spoj.com/problems/QCJ3/
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
using namespace std;
 
int main(){
 
    w(t){
        ll n;
        cin>>n;
        ll arr[n+1],xr=0;
        f(i,1,n+1){
            cin>>arr[i];
            if(arr[i]%2!=0) xr^=i;
        }

        if(xr!=0) cout<<"Tom Wins"<<endl;
        else cout<<"Hanks Wins"<<endl;
    }   
     
    return 0;
}