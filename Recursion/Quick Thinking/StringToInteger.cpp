//convert a string to a integer

#include<bits/stdc++.h>
using namespace std;

int StringToInteger(string s,int n){
    //base case
    if(n==0) return 0;
    //rec case
    int digit=s[n-1] - '0'; //storing the last digit of the number
    int small_ans=StringToInteger(s,n-1); //calling the recursive function on the remaining string except for the last digit
    // ex: s="2048"
    // digit = '8'-'0'=8;
    // small_ans=StringToInteger("204",3);
    // now StringToInteger() will return string "204" as integer 204, so to get 2048 - multiply 204 with 10 and add 8.
    // 204*10 + 8 => 2048
    return small_ans*10+digit;
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    cout<<StringToInteger(s,n)<<endl;
}