#include<bits/stdc++.h>
using namespace std;

void generate_brackets(int n,char *out,int opening,int closing,int i){
    //base case
    int nn=n*2;
    if(i==nn){
        out[i]='\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    if(opening < n){
        //for opening brackets]
        out[i]='(';
        generate_brackets(n,out,opening+1,closing,i+1);
    }
    //for closing brackets
    if(closing < opening){
        out[i]=')';
        generate_brackets(n,out,opening,closing+1,i+1);
    }
}

int main(){
    int n;
    cin>>n;
    char out[100];
    generate_brackets(n,out,0,0,0);
}