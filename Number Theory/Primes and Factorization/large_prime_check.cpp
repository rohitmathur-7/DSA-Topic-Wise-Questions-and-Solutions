/*
    Ques: Given a large number in the range 0 to 10^13, check if the given number is prime or not.
*/


/*
    Now we can only create our bitset sieve till 10^7, so we can't directly check if the number is prime or not....So we have to iterate from 0 to sqrt(n) in our bitset sieve, and if some number divides the given number, then it is not prime otherwise it is prime.
*/



#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;
bitset<10000005> b;
vector<int> primes;

void sieve(){
	b[0]=b[1]=1;
	b.set(); //sets all the bits as 1	
	for(long long int i=2;i<=10000000;i++){
		if(b[i]){
			primes.push_back(i);
			for(long long int j=i*i;j<=10000000;j+=i){
				b[j]=0;	
			}
		}
	}
}

bool isPrime(ll n){
    //if the number is in rang 0 to 10^7, then we can directly check if it is a prime or not, and it will only take O(1) time.
    if(n<=10000000){
        return b[n]==1?true:false;
    }
    //but if number > 10^7, then we will iterate from 0 to sqrt(n), and if some number divides it completely, then it is not a prime...otherwise it is a prime!
    for(ll i=0;primes[i]*(ll)primes[i]<=n;i++){
        if(n%primes[i]==0) return false;
    }

    return true;
}

int main(){
    sieve();
    ll n;
    cin>>n;
    if(isPrime(n)) cout<<"It is a Prime!"<<endl;
    else cout<<"NO, not a Prime!"<<endl;
}