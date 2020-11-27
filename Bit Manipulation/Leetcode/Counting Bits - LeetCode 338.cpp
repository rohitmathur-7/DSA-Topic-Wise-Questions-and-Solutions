#include<bits/stdc++.h>
using namespace std;

//** QUES - COUNTING BITS (LEETCODE 338) **
//WE ARE GIVEN A NUMBER(NUM) AND WE NEED TO RETURN A VECTOR WHICH WILL CONTAIN THE NUMBER OF SET BITS OF EACH NUMBER FORM 0 TO NUM.
//EX: 
//NUM = 3
//NOW WE NEED TO RETURN A VECTOR WHICH WILL HAVE - 
//	[number of set bits in 0 , number of set bits in 1 , number of set bits in 2 , number of set bits in 3]  
//	Ans: [0,1,1,2]
//	as: 
//	0 - 0
//	1 - 1
//	2 - 1 0
//	3 - 1 1 0
	
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++){
            int cnt=0;
            int r=i;
            while(r){
                cnt++;
                r=r & (r-1);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main(){
	int num;
	cin>>num;
	Solution s;
	vector<int> ans=s.countBits(num);
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
