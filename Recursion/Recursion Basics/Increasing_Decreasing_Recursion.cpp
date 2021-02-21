#include<bits/stdc++.h>
using namespace std;

void increasing(int n){
    //base case
    if(n==1){
        cout<<1;
        return;
    }
    //recursive case
    increasing(n-1);
    cout<<n;
}

void decreasing(int n){
    //base case
    if(n==1){
        cout<<1;
        return;
    }
    //recursive case
    cout<<n;
    decreasing(n-1);
}


int main(){
    int n;
    cin>>n;
    increasing(n);
    cout<<endl;
    decreasing(n);
}