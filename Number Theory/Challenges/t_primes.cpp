/*
    Ques: 
    We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

    You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

    Input Format
    First Line : n , Number of elements in an array Second Line : xi ( i from 1 to n)

    Constraints
    n <= 10^5 xi <= 10^12

    Output Format
    YES if its T-Prime NO if its not a T-Prime

    Sample Input
    3
    4 5 6

    Sample Output
    YES
    NO
    NO

    Explanation
    The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5). The third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;
vl primes;   
                     
int main(){

    ll n;
    cin>>n;
    f(i,0,n){
        ll x;
        cin>>x;
        ll ans=2;
        ll power=0;
        f(i,2,sqrt(x)+1){
            if(x%i==0){
                ans++;
                while(x%i==0){
                    ll temp=x/i;
                    if(temp%i!=0 && temp!=1){
                        ans++;
                    }
                    x/=i;
                    power++;
                }
            }
        }
        
        if(ans==3 && power==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    
    }
    return 0;
}