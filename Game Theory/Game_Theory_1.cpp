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

// set<ll> findDivisors(ll n){
//     set<ll> s;
//     for(ll i=2;i*i<=n;i++){
//         if(n%i==0){
//             if((n/i)==i) s.insert(i);
//             else{
//                 s.insert(i);
//                 s.insert(n/i);
//             }
//         }
//     }
//     s.insert(1);

//     return s;
// }  

// ll findMex(set<ll> st){
//     ll mx=0;
//     while(st.find(mx)!=st.end()) mx++;
//     return mx;
// }

// ll calculateGrundy(ll n){
//     if(n==0) return 0;
//     if(n==1) return 0;

//     set<ll> s = findDivisors(n);
//     set<ll> st;
//     for(auto x:s){
//         st.insert(calculateGrundy(x));
//     }   
    
//     ll mx = findMex(st);
//     return mx;
// }

/*
    Explanation:
    as all n piles are of same height m, so if n is even then xor will be zero so 2 will win, and if n is odd then there can be 2 cases...if grundyNumber(m)==0 then 2 will win bcz 1 will not be able to make even a single move , else if grundyNumber(m)!=0 then 1 will win.

    And as only 1 will have grundy number as 0 so we can just check if m is 1 or not.

    What it means when we say grundyNumber(m)=0, it means that the first player will not even have a single move to play as all the piles will be of 1 size.
*/

int main(){
 
    w(t){
        ll n,m;
        cin>>n>>m;
        // ll grundy_number = calculateGrundy(m);
        if(n%2==0) cout<<2<<endl;
        else{
            // if(grundy_number==0) cout<<2<<endl;  *if using this then we have to use all above functions.
            if(m==1) cout<<2<<endl; //*but we can do directly this too
            else cout<<1<<endl;
        }
    }
     
    return 0;
}