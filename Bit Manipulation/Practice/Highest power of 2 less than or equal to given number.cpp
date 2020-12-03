
** QUES - HIGHEST POWER OF 2 LESS THAN OR EQUAL TO GIVEN NUMBER **

** METHOD 1 **
int powerOfTwo(int n){
	int res;
	for(int i=0;i<sizeof(unsigned int);i++){
		int curr=1<<i;
		if(curr>n) break;
		res=curr;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	cout<<powerOfTwo(n);
}

** METHOD 2 **
int powerOfTwo(int n){
	int p=(int)log2(n);
	return (int)(1<<p);
}

int main(){
	int n;
	cin>>n;
	cout<<powerOfTwo(n);
}

** METHOD 3 - USING GCC COMPILER FUNCTIONS **
   T.C - O(1)
int log(int x) {
    return 1<<32 - __builtin_clz(x) - 1;
}
int main(){
	int x;
	cin>>x;
	cout<<log(x);
}
