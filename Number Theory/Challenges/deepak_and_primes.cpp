/*

    Ques: 
    Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

    Input Format
    Single line containing integral value n.

    Constraints
    1<=n<=500000

    Output Format
    Integral value denoting nth prime number.

    Sample Input
    1
    Sample Output
    2

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
bitset<10000000> b;
vector<int> primes;

void bitset_sieve(){
	b[0]=1,b[1]=1;
	b.set();
	f(i,2,10000001){
		if(b[i]){
			primes.pb(i);
			for(ll j=i*i;j<=10000000;j+=i){
				b[j]=0;
			}		
		}
	}
}
                     
int main(){
	bitset_sieve();
    ll n;
    cin>>n; 
	cout<<primes[n-1]<<endl;
    return 0;
}