
** QUES - Compute XOR from 1 to n (direct method)    T.C - O(1)**
** Direct XOR of all numbers from 1 to n (EFFICIENT METHOD) **
int computeXOR(int n) 
{ 
	if (n % 4 == 0) 
		return n; 
	if (n % 4 == 1) 
		return 1; 
	if (n % 4 == 2) 
		return n + 1; 
	else
		return 0; 
} 

int main(){
	int n;
	cin>>n;
	cout<<omputeXOR(n);
}

