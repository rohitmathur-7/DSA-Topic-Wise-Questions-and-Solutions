/*
 Space optimized version of Sieve Of Eratosthenes.
 More Space = More range of prime numbers we can store

    if we have bool b[100], it takes = 100bytes = 800bits
    but,
    if we take bitset<100> b, it takes = 100bits

    So now we will have 8X more space if we use bitset instead of bool array.

*/

//** QUES: Using Bitset Sieve compute the prime numbers. **
#include<bits/stdc++.h>
using namespace std;

bitset<10000000> b;
vector<int> primes;

bool isPrime(long long int n){
	if(n<=10000000){
		return b[n]==1?true:false;
	}	
	for(long long int i=0;primes[i]*(long long int)primes[i]<=n;i++){
		if(n%primes[i]==0) return false;
	}
	return true;
}


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

int main(){
	sieve();	
	long long int n;
	cin>>n;
	if(isPrime(n)) cout<<"It is prime!"<<endl;
	else cout<<"Not prime!"<<endl;
	//for(int i=0;i<=100;i++) cout<<primes[i]<<" ";  //First 100 primes
}