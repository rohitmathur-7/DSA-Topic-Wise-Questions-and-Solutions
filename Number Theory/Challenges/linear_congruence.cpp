/*  
    //Chinese Remainder Theorem
    
    Ques:
    Alice has mastered number theory, now he gives you the task of solving linear congruence. You need to print the minimum positive value of x which satisfy the following conditions:
    x mod a0 = r0
    x mod a1 = r1
    .
    .
    x mod ak-1 = rk-1
    Every pair in a0…….ak-1 is co-prime.

    Input Format
    First line contains single integer k. Second line contains numbers array 'a'. Third line contains remainder array 'r'.

    Constraints
    The product of all numbers in array 'a' will fit in long long int.

    Output Format
    Print integral value denoting minimum positive value of x satisfying the equations.

    Sample Input
    3
    3 4 5
    2 3 1
    Sample Output
    11

    Explanation -
    Use chinese remainder theorem.
    formula = (Σ(remainer[i]*pp[i]*inverse[i]))%product  (i=[0,k-1])

    pp[i] = product of all numbers given in num array except num[i].
    pp[i] = product/num[i]

    inverse[i] = multiplicative modulo inverse of pp[i] with respect to num[i]

    product = num[i]*num[i+1]* ....*num[k-1]

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
ll x,y,GCD;

ll fast_modulo_exponentation(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans%m;
}

ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}

void extendedEuclidAlgorithm(ll a,ll b){
    //base case
    if(b==0){
        x=1;y=0;
        GCD=a;
        return;
    }
    //rec case
    extendedEuclidAlgorithm(b,a%b);
    ll cx=y;
    ll cy=x-((a/b)*y);

    x=cx;
    y=cy;
}

ll multiplicative_modulo_inverse(ll a,ll m){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        return (x+m)%m;
}
                     
int main(){

    ll k;
    cin>>k;
    ll num[k],rem[k];
    ll product=1;
    f(i,0,k){
        cin>>num[i];
        product*=num[i];
    }
    f(i,0,k){
        cin>>rem[i];
    }

    ll ans=0;
    f(i,0,k){
        ll pp=product/num[i];
        ll inverse=multiplicative_modulo_inverse(pp,num[i]);
        ans+=(rem[i]*pp*inverse);
    }

    ans%=product;
    cout<<ans<<endl;

    return 0;
}