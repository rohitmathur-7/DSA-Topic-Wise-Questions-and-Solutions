// QUES: Count binary strings of length of N, which have no cosecutive ones?

#include<bits/stdc++.h>
using namespace std;

int count_binary_strings(int n){
    //base case
    if(n==0) return 1;
    if(n==1) return 2;
    //rec case
    // f(n) - number of valid strings with length n
    //if we have 0 as the last or first char in the string, then for remaining n-1, f(n-1) will give number of valid strings with length n-1.
    //now if the string ends or begins with 1, then the previous pr next char should definitely be a 0, otherwise it won't be a valid string...bcz then we will get 2 consecutive 1's.
    // So, f(n-2) will give number of valid strings with length n-2.
    return count_binary_strings(n-1)+count_binary_strings(n-2);
}


int main(){
    int n;
    cin>>n;
    cout<<count_binary_strings(n)<<endl;
}
