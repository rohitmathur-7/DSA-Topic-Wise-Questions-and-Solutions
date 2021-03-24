/*
In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

Alice is very weak in maths section. Help her to find the number of such n digit integers.

Input Format
The first line contains T, the number of test cases. Further T lines contains the value n which is the number of digit in the integer.

Constraints
1<=T<=20
1<=n<=25

Output Format
For each test case print the number of such n digit integer.

Sample Input
3
1
2
3
Sample Output
#1 : 2
#2 : 3
#3 : 5
Explanation
For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, baa, bab
*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int ans=0;
bool g=false;

void solve(int i,char * output,int n){
    //base case
    if(i==n){
        output[i]='\0';
        // cout<<output<<" ";
        ans++;
        return;
    }

    //rec case
    output[i]='a';
    solve(i+1,output,n);
    if(output[i-1]=='b' && (i-1)>=0) return;
    output[i]='b';
    solve(i+1,output,n);

}

int main(){
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        char output[100];
        cout<<"#"<<cnt<<" : ";
        solve(0,output,n);
        cout<<ans;
        ans=0;
        cout<<endl;
        cnt++;
    }
}