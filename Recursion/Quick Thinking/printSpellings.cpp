//input a number ex: 2048 output: two zero four eight

#include<bits/stdc++.h>
using namespace std;
string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

//using stringstream

// void printSpellings(int n){
//     stringstream ss;
//     ss<<n;
//     string s;
//     ss>>s;
//     for(int i=0;i<s.size();i++){
//         int a=s[i]-'0';
//         cout<<num[a]<<" ";
//     }
// }

//using recursion

// void printSpellings(int n){
//     //base case
//     if(n==0) return;
//     //rec case
//     int x=n%10;
//     printSpellings(n/10);
//     cout<<num[x]<<" ";
//     return;
// }

int main(){
    int n;
    cin>>n;
    printSpellings(n);
}