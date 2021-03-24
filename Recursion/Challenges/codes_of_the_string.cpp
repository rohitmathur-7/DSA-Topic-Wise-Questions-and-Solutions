/*
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void generate_codes(string s,char *output,int i,int n,vector<string> &v){
    //base case
    if(s[i]=='\0'){
        output[i]='\0';
        v.push_back(output);
        return;
    }
    //rec case
    output[i]=alpha[s[i]-'0'-1];
    generate_codes(s,output,i+1,n,v);
    output[i]=' ';
    int num1=s[i]-'0';
    if((i+1) < n){
        int num2=s[i+1]-'0';
        int num3=(num1*10)+num2;
        if((num3) <= 26){
            output[i]=alpha[num3-1];
            generate_codes(s,output,i+2,n,v);
            output[i]=' ';
        }    
    }
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    char output[100];
    vector<string> v;
    generate_codes(s,output,0,n,v);
    for(int i=0;i<v.size();i++){
        if(i==0){
            cout<<"[";
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==' ') continue;
                else cout<<v[i][j];
            }
            cout<<",";
        }
        else if(i<v.size()-1){
            cout<<" ";
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==' ') continue;
                else cout<<v[i][j];
            }
            cout<<",";
        }
        else{
            cout<<" ";
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==' ') continue;
                else cout<<v[i][j];
            }
            cout<<"]";
        }
    }
    cout<<endl;
    return 0;
}