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
                     
/*
    T.C -> O(N^2)
*/

ll wine_top_down_dp(ll p[],ll y,ll a,ll b,ll dp[100][100]){
    
    //base case -> no wine bottles left
    if(a>b) return 0;

    //rec case
    //lookup for if the value is already computed
    if(dp[a][b]!=0) return dp[a][b];
    ll oo=(p[a]*y)+wine_top_down_dp(p,y+1,a+1,b,dp);
    ll ot=(p[b]*y)+wine_top_down_dp(p,y+1,a,b-1,dp);
    dp[a][b]=max(oo,ot);

    return dp[a][b];
} 

int main(){
 
    ll n;cin>>n;
    ll p[n];
    f(i,0,n){
        cin>>p[i];
    }
    
    ll dp[100][100]={0};
    cout<<wine_top_down_dp(p,1,0,n-1,dp)<<endl;
    
    return 0;
}