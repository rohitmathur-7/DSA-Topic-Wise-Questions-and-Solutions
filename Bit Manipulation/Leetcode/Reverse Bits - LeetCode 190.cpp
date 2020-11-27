#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

//** QUES - REVERSE BITS (LEETCODE 190)
//WE ARE GIVEN A 32 BITS UNSIGNED INTEGER.
//ALL WE NEED TO DO IS REVERSE THE BITS OF THIS NUMBER.
//EX: 
//	N = 100          N = 10010
//	ANS: 001		 ANS: 01001



//YOU ONLY NEED TO WRITE THIS PART WHILE SUBMITTING ON LEETCODE
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result=0;
        for(int i=0;i<32;i++){
            int lsb= n & 1;
            int rlsb= lsb << (31-i);
            result = result | rlsb;
            n>>=1;
        }
        return result;
    }
};


//YOU DON'T NEED TO WRITE THIS PART WHILE SUBMITTING ON LEETCODE
int main(){
	uint32_t n;
	cin>>n;
	Solution s;
	cout<<s.reverseBits(n);
}









