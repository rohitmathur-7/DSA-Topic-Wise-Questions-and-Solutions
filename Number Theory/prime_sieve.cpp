//Time Complexity - O(nlog(logn))

#include<bits/stdc++.h>
using namespace std;

void prime_sieve(long long *p,long long n){
	for(long long i=3;i<=100000;i+=2) p[i]=1;
	
	for(long long i=3;i<=100000;i+=2){
		if(p[i]==1){
			for(long long j=i*i;j<=100000;j+=i){
				p[j]=0;
			}	
		}
	}
	p[2]=1;
	p[1]=0;p[0]=0;
	for(long long i=0;i<=n;i++){
		if(p[i]==1) cout<<i<<" ";
	}
}

int main(){
	long long n;
	cin>>n;
	long long p[100000]={0};
	prime_sieve(p,n);
	return 0;
}