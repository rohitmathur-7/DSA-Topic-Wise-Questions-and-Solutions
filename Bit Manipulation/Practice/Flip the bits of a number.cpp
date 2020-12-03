
** QUES -  FLIP THE BITS OF A NUMBER **
SIMPLE APPROACH - JUST SUBTRACT THE NUMBER FROM THE VALUE OBTAINED WHEN ALL BITS ARE EQUAL TO 1.
EX: N=23(10111)     VALUE =11111
	VALUE-N= 11111-10111 -> 01000  
	HENCE THE DIGITS ARE FLIPPED.

int flip(int n){
	int p=(int)log2(n);
	int num=1<<p;
	num=num|(num-1);
	return num-n;
}

int main(){
	int n;
	cin>>n;
	cout<<flip(n);
}
