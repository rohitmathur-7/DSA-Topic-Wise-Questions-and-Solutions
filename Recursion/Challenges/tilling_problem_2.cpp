//QUES: Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.   

/*
Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll arr[n+1];
        arr[0]=1ll;
        for(ll i=1;i<=n;i++){
            arr[i]=arr[i-1];    //placing horizontally
            arr[i]+=((i-m)>=0?arr[i-m]:0);  //placing vertically
            arr[i]%=mod;
        }
        cout<<arr[n]<<endl;  
    }
}