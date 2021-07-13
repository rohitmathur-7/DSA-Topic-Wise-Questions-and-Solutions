/*
    Ques:
    -----
    
    You are given N piles of stones.
    Each pile has some number of stones Mi.
    Two players 1 and 2 play a game in which player 1 always moves first.
    The rules are :-
    1.Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
    2.Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
    You have to find the winner.

    Input Format
    First line consists of number of test cases T. Each test case consists of an integer N. Then follow N integers denoting number of stones in ith pile.

    Constraints
    1 <= T <= 100
    1 <= N <= 100
    1 <= Mi <= 1000000

    Output Format
    First line consists of number of test cases T. Each test case consists of two integers N and M.

    Sample Input
    2
    2 
    1 2
    3 
    1 2 3
    Sample Output
    1
    2

    Explanation: 
    ------------

    We will do this using Sprague Grundy Algorithm because in this game we cannot pick all the stones in a pile all at once, 
    we have constraints over what can we pick from a pile..So we have to use Sprague Grundy only and not NIM GAME.

    Now we will treat each pile as a seperate game and deal with it accordingly.
    So in Spague Grundy the ans is - 

    XORR = G(p1)^G(p2)^...G(pn)   (Here p1,p2...pn are the given pile heights)
                                  (Here G(p1) is the grundy number of p1)
    If(XORR!=0) then A is winner.
    else B is winner.

    Now , 
    From a pile we can only go to a number which is divisor of its height i.e if A is height of a pile, then A can only be reduced to B if B is divisor of A and B!=A. (1<=B<A).

    So what we will do is iterate over the height of each pile and calculate GrundyNumber of Height of each pile and Xor them all in the end.

    If(XORR!=0) then A is winner.
    else B is winner.
    
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
map<ll,ll> mpp;

ll MEX(set<ll> st){
    ll mx=0;
    while(st.find(mx)!=st.end()) mx++;
    return mx;
}

ll grundy(ll n){
    //base case
    if(n==1) return 0;
    
    if(mpp.count(n)) return mpp[n];

    ll tmp=n;
    set<ll> st;
    st.insert(grundy(1));
    for(ll j=2;j*j<=n;j++){
        ll x=j;
        if(n%x==0){
            if((n/x)==x){
                st.insert(grundy(x));
            }
            else{
                st.insert(grundy(x));
                st.insert(grundy(n/x));
            }
        }
    }
    
    ll ans=MEX(st);
    mpp[tmp]=ans;
    return ans;
}
 
int main(){
  
    w(t){
        ll n;
        cin>>n;
        ll arr[n],xr=0;
        f(i,0,n){
            cin>>arr[i];
        }

        f(i,0,n){
            ll a=grundy(arr[i]);
            xr^=a;
        }

        if(xr!=0) cout<<1<<endl;
        else cout<<2<<endl;
    }
     
    return 0;
}