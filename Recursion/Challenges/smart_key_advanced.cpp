/* QUES:
Given a long vector of strings, print the strings that contain the strings generated by numeric string str.

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
For example, if the input is 26 and the string is coding, then output should be coding since 26 can produce co which is contained in coding.

Input Format
A numeric string str

Constraints
len(str) < 10
No of strings in the vector < 10

Output Format
Each matched string from the given vector.

Sample Input
34
Sample Output
vidhi
divyam
sneha
Explanation
34 will result into combinations :

*dg         *eg         *fg
*dh            *eh         *fh
*di            *ei         *fi
Corresponding strings are output.

vidhi contains dh
divyam contains di
sneha contains eh

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void solve(string n,char *output,int i,vector<string> &v){
    //base case
    if(i==n.size()){
        output[i]='\0';
        // cout<<output<<endl;
        v.push_back((output));
        return;
    }
    //rec case
    int num=n[i]-'0';
    for(int j=0;j<table[num].size();j++){
        output[i]=table[num][j];
        solve(n,output,i+1,v);
    }
    return;
}

int main(){
    string n;
    cin>>n;
    char output[100];
    vector<string> v;
    solve(n,output,0,v);
    sort(v.begin(),v.end());
    for(int i=0;i<11;i++){
        for(auto x:v){
            int p1=0;
            for(int j=0;j<searchIn[i].size();j++){
                if(searchIn[i][j]==x[p1]){
                    p1++;
                    if(p1==x.size()){
                        cout<<searchIn[i]<<endl;
                        break;
                    }
                }
                else p1=0;
            }
        }
    }
}