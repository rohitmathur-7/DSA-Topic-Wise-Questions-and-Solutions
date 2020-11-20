#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

// ** QUES - **COUNTING NUMBER OF SET BITS** **
//	  In this question we have to find out how many set bits(1) are present in a number's binary representation.
//	  Ex: n=5   5(decimal)- 0101(binary)
//	  	  Number of Set bits(1) = 2
//** METHOD 1 -      TIME COMPLX: 0(log(n));
//int main(){
//	int n;
//	cin>>n;
//	int cnt=0;
//	while(n){
//		if(n & 1 ==1) cnt++;
//		n>>=1;
//	}
//	cout<<cnt;
//}
//
////** METHOD 2 -      TIME COMPLX: 0(no. of set bits)[best case]   O(log(n))[worst case];
//// So method 2 is a bit better bcz its best time is O(no. of set bits) while for Method 1 O(log(n)) is the time complx in every case.
//int main(){
//	int n;
//	cin>>n;
//	int cnt=0;
//	while(n){
//		cnt++;
//		n=n & (n-1);
//	}
//	cout<<cnt;
//}
