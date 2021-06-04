/*

    Ques:
    You are given an array containing n elements. Xor of an array is defined as the xor of all the elements present in the array. You can remove atmost one element from the array to maximize the value of XOR of array. Find the maximum XOR value you can get for the resulting array.

    Input Format
    First line of input contains an integer n denoting the size of the array. After that n lines follow, where the i th line contains the i'th element of the array.

    Constraints
    1 <= n <= 1000000 0 <= elements of array <= 10^18

    Output Format
    You have to print a single integer denoting the maximum xor you can get for the resulting array.

    Sample Input
    3
    1
    2
    3
    Sample Output
    3
    Explanation
    After removing 3 from the array, the xor of the resulting array = 1 ^ 2 = 3 which is the maximum value you can attain.

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
                     
int main(){

    ll n;
    cin>>n;
    ll arr[n],xr;
    f(i,0,n){
        cin>>arr[i];
        if(i==0) xr=arr[i];
        else xr^=arr[i];
    }

    ll ans=xr;

    f(i,0,n){
        ans=max(ans,xr^arr[i]);
    }

    cout<<ans<<endl;
     
    return 0;
}