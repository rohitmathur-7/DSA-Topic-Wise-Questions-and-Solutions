/*Ques: Prime Visits
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.

Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.
*/


#include<bits/stdc++.h>
using namespace std;

void prime_sieve(long long *p){
	for(long long i=3;i<=1000000;i+=2) p[i]=1;
	for(long long i=3;i<=1000000;i+=2){
		if(p[i]==1){
			for(long long j=i*i;j<=1000000;j+=i){
				p[j]=0;
			}
		}
	}
	p[2]=1;
	p[0]=p[1]=0;
}

int main(){
	long long t;
	cin>>t;
	long long p[1000005]={0};
	prime_sieve(p);
	while(t--){
		long long a,b;
		cin>>a>>b;
		long long ans=0;
		for(long long i=a;i<=b;i++){
			if(p[i]==1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}