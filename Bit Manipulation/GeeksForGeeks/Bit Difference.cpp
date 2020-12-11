** QUES - Bit Difference **

//User function Template for C++

// Function to find number of bits to be flip
// to convert A to B
** METHOD 1 - **
int countBitsFlip(int a, int b){
    int cnt=0;
    for(int i=0;i<32;i++){
        int x=a&1;
        int y=b&1;
        if(x!=y) cnt++;
        a=a>>1;b=b>>1;
    }
    return cnt;
}

** METHOD 2 - **
int countBitsFlip(int a, int b){
    return __builtin_popcount(a^b);
}

** Explanation of Method 2 - **
EX: a=20 b=25

	a=10100
	b=11001
  a^b=01101  

[As we know XOR gives 1 as result when both the bit areb different!..So we just need to count the number of 1 in the XOR of a and b
																		,which is obtained by using __builtin_popcount() function.]
  				
  				__builtin_popcount() - This is a GCC compiler function which gives us the count of set bits(1) in our number.
  				


