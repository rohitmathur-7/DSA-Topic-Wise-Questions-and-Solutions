// QUES: Given a number n, find the number of ways in which you can reach n, when you can take a jump of either 1,2 or 3.

#include<bits/stdc++.h>
using namespace std;

int ladder_problem(int n){
    //base case
    if(n<0) return 0; 
    if(n==0) return 1; //n==0 means how many ways are there to stand on the ground, so obviously there is only 1 way.
    //rec case
    //we can take the first step as 1, then the remaining n-1 steps can be walked in f(n-1) ways, same for 2 and 3.
    return (ladder_problem(n-1)+ladder_problem(n-2)+ladder_problem(n-3));
}

int main(){
    int n;
    cin>>n;
    cout<<ladder_problem(n)<<endl;
} 