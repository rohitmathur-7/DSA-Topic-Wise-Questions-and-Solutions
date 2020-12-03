** QUES - CHECK IF ALL BITS OF A NUMBER ARE SET **   

- IF ALL THE BITS OF A NUMBER ARE SET, THEN IF WE ADD 1 TO THE NUMBER....THEN WE WILL OBTAIN A NUMBER THAT WOULD BE PERFECT POWER OF 2.
	T.C - O(1);
  EX - 
  		N=7(111)
		N+1=8(1000)
		
		0111
	&	1000
		----
		0000
		----
  	    		(N & N+1) = 0000

bool allBitsSet(int n){
	if(((n+1) & n) == 0) return true;
	else return false;
}

int main(){
	int n;
	cin>>n;
	if(allBitsSet(n)) cout<<"YES";
	else cout<<"NO";
}
