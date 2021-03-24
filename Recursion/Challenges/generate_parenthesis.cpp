//QUES: Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.

/*
Sample Input
2
Sample Output
()() 
(())
*/


#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

void generate_parenthesis(int n,char *out,int open,int close,int i,vector<string> &s){
    //base case
    int nn=n*2;
    if(i==nn){
        out[i]='\0';
        s.push_back(out);
        return;
    }
    //rec case
    if(open<n){
        out[i]='(';
        generate_parenthesis(n,out,open+1,close,i+1,s);
    }
    if(close<open){
            out[i]=')';
            generate_parenthesis(n,out,open,close+1,i+1,s);
    }
}


int main(){
    int n,open,close;
    cin>>n;
    char out[100];
    
    vector<string> s;
    generate_parenthesis(n,out,0,0,0,s);
    sort(s.begin(),s.end(),greater<string>());
    for(auto x:s){
        cout<<x<<endl;
    }
    return 0;
}
