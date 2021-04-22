/*
Ques:
For a given number n, form a list and insert the following pattern into the list at the same position sequentially.
{floor(n/2) , n%2 , floor(n/2) }
Until every element in the list is either 1 or 0. Now, calculate number of 1s in from l to r (1-indexed).

EXPLAINATION: Start from n. Then make a list with the following elements.i.e. {floor(n/2) , n%2 , floor(n/2) }. Now this list has three elements. Now further break down each of those 3 elements considering the new n to be floor(n/2) , n%2 and floor(n/2) respectively for those three elements respectively INPLACE. And this process will go on until the n reduces down to 1 or 0. So it will basically form a tree with 3 branches coming out of every node at every level starting from 1 node (n) at the root.
Input Format
Three integers n , l , r

Constraints
0 ≤ n < 10^12, 0 ≤ r - l ≤ 10^6, 1 ≤ l ≤ r

Output Format
Single line containing number of 1s in the given range.

Sample Input
9 6 9
Sample Output
3
Explanation
9 will have the sequence : 101010111010101
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

ll solve(ll s,ll e,ll l,ll r,ll n){

    if(r<s || l>e || s>e) return 0;

    ll mid=(s+e)/2;
    ll ans=0;
    if(mid>=l && mid<=r && n%2==1){
        ans++;
    }
    ans+=solve(s,mid-1,l,r,n/2);
    ans+=solve(mid+1,e,l,r,n/2);
    return ans;
}

int main(){
    ll n,l,r;
    cin>>n>>l>>r;
    ll lg=log2(n)+1;
    ll s=1;
    ll e=pow(2,lg)-1;
    cout<<solve(s,e,l,r,n)<<endl;
    return 0;
}