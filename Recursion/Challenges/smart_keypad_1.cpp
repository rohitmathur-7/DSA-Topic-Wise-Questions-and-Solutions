/*
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.
*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void solve(string n,char *output,int i){
    //base case
    if(i==n.size()){
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    int num=n[i]-'0';
    for(int j=0;j<table[num].size();j++){
        output[i]=table[num][j];
        solve(n,output,i+1);
    }
    return;
}

int main(){
    string n;
    cin>>n;
    char output[100];
    solve(n,output,0);
}