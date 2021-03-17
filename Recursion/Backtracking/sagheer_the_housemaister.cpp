#include<bits/stdc++.h>
#define nn 100
using namespace std;
int n,m,ls[nn],rs[nn],ans;
string s[nn];


void solve(bool tight,int pos,int value){
    //base case
    if(pos==n-1){
        if(tight){
            ans=min(ans,value+rs[pos]);
        }
        else{
            ans=min(ans,value+ls[pos]);
        }
        return;
    }

    //rec case
    if(tight){
        solve(0,pos+1,value+m+2); //when we take the left stairs
        solve(1,pos+1,value+(2*rs[pos])+1); //when we take the right stairs
    }
    else{
        solve(0,pos+1,value+(2*ls[pos])+1); //when we take the left stairs
        solve(1,pos+1,value+m+2);//when we take the right stairs
    }

}

int main(){
    cin>>n>>m;
    for(int i=n-1;i>=0;i--){
        cin>>s[i];
    }
    int tmp=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            if(s[i][j]=='1'){
                ls[i]=max(j,ls[i]);    //setting the distance of room with light on(1) from left
            }
            if(s[i][m-j+1]=='1'){
                rs[i]=max(j,rs[i]);    //setting the distance of room with light on(1) from right
            }
        }
        if(ls[i]) tmp=i;
    }

    n=tmp+1; //we are using tmp bcz, suppose the n that we inpur is 4, but the last row is all zeroes and no '1' is present in that row, so that's why we are just taking n as that last row with atleast one '1' present in it.

    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    if(n==1){
        cout<<ls[0]<<endl;
        return 0;
    }

    ans=INT_MAX;
    solve(0,1,(2*ls[0])+1);
    solve(1,1,m+2);

    cout<<ans<<endl;
    return 0;
}