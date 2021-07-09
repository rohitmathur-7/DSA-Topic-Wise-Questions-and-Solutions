/*
    Ques: https://www.spoj.com/problems/MMMGAME/
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
        ll arr[n],xr=0;
        bool all_one=true;
        f(i,0,n){
            cin>>arr[i];
            xr^=arr[i];
            if(arr[i]!=1) all_one=false; 
        }

        if(all_one){
            if(n%2==0) cout<<"John"<<endl;
            else cout<<"Brother"<<endl;
        }
        else{
            if(xr!=0) cout<<"John"<<endl;
            else cout<<"Brother"<<endl;
        }
    }
     
    return 0;
}