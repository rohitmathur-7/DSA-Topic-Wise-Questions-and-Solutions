//**NOTE : THIS IS NOT A LEETCODE QUESTION! ..IT'S JUST FOR PRACTICE**

// ** QUES - **TOTAL SUM OF ALL PAIR** **
//	  Given an array with n elements ,calculate -
//	  	(A1^A2)+(A1^A3)+.....(A1^An)+
//	  			(A2^A3)+.....(A2^An)+
//	  								.
//	  								.
//	  						(An-1^An)		
//
//	ex - 5,9,7,6
//	5^9=12
//	5^7=2
//	5^6=3
//	9^7=14
//	9^6=15
//	7^6=1
//			Total =47
//
//** METHOD 1 - Use 2 nested for loops    Time complx- O(n^2); **
//** METHOD 2 - 						  Time complx- O(nlog(n)); **
//	Ex - 5,3,9			5-0101 		3-0011		9-1001
//	5^3=0110					  
//	5^9=1100	
//	3^9=1010		Total Sum = 0*(2^0)+2*(2^1)+2*(2^2)+2*(2^3)
//							  = 28
//	Okay so we find the number of set bits(1) and Zeros at a particular position.
//	Eg: 
//	5^3=0110       at 0th pos there is 0;   at 1st pos there is 1 .....
//	5^9=1100       at 0th pos there is 0;	at 1st pos there is 0 .....
//	3^9=1010   	   at 0th pos there is 0;	at 1st pos there is 1 .....
//	
//	So all we do is keep count of numbers of 1s and 0s at a particular pos.(As we know that for XOR value to be 1 ,one bit should be 1 and the other 0).
//	So the answer would be ans=(nmber of 1s*number of 0s)*(2 to the power of the particular position)

int main(){
	int n;
	cin>>n;
	int arr[1000];
	int res=0;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=0;i<32;i++){
		int cz=0,co=0;
		for(int j=1;j<=n;j++){
			if(arr[j] & (1<<i)) co++;
			else cz++;
		}
		int m=cz*co;
		res+=m*(1<<i);
	}
	cout<<res;
}

