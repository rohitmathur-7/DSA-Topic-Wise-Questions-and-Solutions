
// ** QUES - **ALL PAIR SUM XOR** **

//In this question ARE given n numbers.
//we want to find out the all pair sum. i.e if we have A1 A2 ....An   
//Then We want to calculate -
//(A1 + A1)^(A1 + A2)^......(A1 + An)^                (WHERE '^' - XOR OPERATION)
//(A2 + A1)^(A2 + A2)^......(A2 + An)^
//(A3 + A1)^(A3 + A2)^......(A3 + An)^
//.
//.
//(An + A1)^(An + A2)^......(An + An)^

//**Method 1 - We just apply two loops.  Time Complexity - o(n^2);
//**Method 2 - 							 Time Complexity - o(n);
//	for ex - 2 ,4 ,1
//	(2+2)^(2+4)^(2+1)^      4^6^3^  <----Matrix
//	(4+2)^(4+4)^(4+1)^  == 	6^8^5^  == 14
//	(1+2)^(1+4)^(1+1)^		3^5^2
//	
//	And now as we know that if there is a numeber 'a' then a^a=0
//	as in XOR only if both the bits are diff(i.e one is 1 and the other 0) then only it will output 1 otherwise 0.
//	So by this observation, we see that the numbers are repeating in the matrix only except the diagoanl elements.
//	As (1,3) is repeated as (3,1)....but the diagoanl elements like (1,1) , (2,2)...Comes only one time.
//	So now we will just take the XOR of the diagonal elemnets and that will bw our answer.
	
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=2*arr[0];
	for(int i=1;i<n;i++){
		ans^=2*arr[i];
	}	
	cout<<ans;
}

