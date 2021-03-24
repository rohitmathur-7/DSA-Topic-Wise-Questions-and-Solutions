/* QUES: 
You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.
Note:

All numbers (including target) will be positive integers
Elements in the combination must be in non-descending order
There should be no duplicate combinations
Input Format
The first line will contain N indicating the number of elements in the array.
The second line will contain space separated N integers , A[i].
The third line will contain the target number T.

Constraints
N <= 15 1<= A[I] <= 100

Output Format
Print all unique combinations of the numbers satisfying the above constraints in a separate line in lexicographic manner.

Sample Input
7
10 1 2 7 6 1 5
8

Sample Output
1 1 6 
1 2 5 
1 7 
2 6 
*/



#include<bits/stdc++.h>
using namespace std;

int n,t;
int arr[15];
vector< vector<int> > ans;  
set< vector<int> > mp; // to avoid duplicate vector of a possible combination

void solve(int i,int t,vector<int> &temp){
    //base case
    if(i>=n || t<0) return;
    if(t==0){
        if(!temp.empty() && mp.find(temp)==mp.end()){
            ans.push_back(temp);
            mp.insert(temp);
            return;
        }
    }

    //rec case
    //include the current number
    temp.push_back(arr[i]);
    solve(i+1,t-arr[i],temp);
    temp.pop_back();//backtrack to remove the current number from the temp vector

    //exclude the current number
    solve(i+1,t,temp);
    return;
}

vector< vector<int> > helper(){
    ans.clear();mp.clear();
    if(n==0 || t==0) return ans;
    sort(arr,arr+n);
    vector<int> temp;
    solve(0,t,temp);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>t;
    ans=helper();
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}