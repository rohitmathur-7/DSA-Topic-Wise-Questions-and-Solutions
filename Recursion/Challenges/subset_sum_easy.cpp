#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int n;
bool g=false;

void solve(ll *arr,ll i,ll sum,ll cnt){
    //base case
    if(i==n){
        if(sum==0 && cnt>0) g=true;
        return;
    }
    //rec case
    //we can have 2 cases, either we can include the current element or not include it!
    solve(arr,i+1,sum+arr[i],cnt+1);
    solve(arr,i+1,sum,cnt);
    return;
}

int main(){
    w(t){
        cin>>n;
        ll arr[n];
        ll x,sum=0;
        f(i,0,n){
            cin>>arr[i];
        }
        solve(arr,0,sum,0);
        if(g) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        g=false;
    }
}