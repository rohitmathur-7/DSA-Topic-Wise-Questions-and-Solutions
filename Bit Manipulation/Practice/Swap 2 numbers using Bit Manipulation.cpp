** QUES - SWAP 2 NUMBERS USING BIT MANIPULATION **
** METHOD 1 - USING BITWISE XOR(QUICKEST WAY TO SWAP TWO NUMBERS) **
int main(){
	int x,y;
	cin>>x>>y;
	x=x^y;
	y=x^y;
	x=x^y;
	cout<<x<<" "<<y;
}

** PROBLEM - **
When we use pointers to variable and make a function swap, the above method fail when both pointers point to the same variable.
 Let’s take a look at what will happen in this case if both are pointing to the same variable.
// Bitwise XOR based method 
x = x ^ x; // x becomes 0 
x = x ^ x; // x remains 0 
x = x ^ x; // x remains 0


** METHOD 2 - (A mixture of bitwise operators and arithmetic operators) **
//Function to swap the numbers.
void swap(int &a,int &b)
{
	//same as a = a + b
	a = (a & b) + (a | b);
	//same as b = a - b
	b = a + (~b) + 1;
	//same as a = a - b
	a = a + (~b) + 1;
}

int main()
{
	int a,b;
	cin>>a>>b;
	swap(a, b);
	cout << "After swapping: a = " << a << 
							", b = " << b;
	return 0;
}
