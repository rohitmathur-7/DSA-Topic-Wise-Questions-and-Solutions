** QUES - Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i **
** EQUAL SUM AND XOR - https://www.geeksforgeeks.org/equal-sum-xor/ **

** METHOD 1(SIMPLE)   T.C - O(N) **
int countValues (int n) 
{ 
	int countV = 0; 
	for (int i=0; i<=n; i++ ) 
		if ((n+i) == (n^i) ) 
			countV++; 

	return countV; 
} 
int main() 
{ 
	int n = 12; 
	cout << countValues(n); 
	return 0; 
} 

** METHOD 2(EFFICIENT)   T.C - O(log(n)) **
IF n+i = n^i...then, n & i=0.
Hence our problem reduces to finding values of i such that n & i = 0. How to find count of such pairs?
We can use the count of unset-bits in the binary representation of n. For n & i to be zero, i must unset all set-bits of n.
If the kth bit is set at a particular in n, kth bit in i must be 0 always, else kth bit of i can be 0 or 1

int ans(int n){
	int unsetBits=0;
	while(n){
		if((n & 1) == 0) unsetBits++;
		n>>=1;
	}
	return 1<<unsetBits;
}

int main(){
	int n;
	cin>>n;
	cout<<ans(n);
}
