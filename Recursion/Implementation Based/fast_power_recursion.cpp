#include<bits/stdc++.h>
using namespace std;

int power(int a,int n){
    //base case
    if(n==0) return 1;
    //recursive case
    return a*power(a,n-1);
}

int fast_power(int a,int n){
    //base case
    if(n==0) return 1;
    //recursive case
    int small=fast_power(a,n/2);
    small*=small;
    if(n&1) return a*small;
    return small;
}

int main(){
    cout<<power(2,10)<<endl;
    cout<<fast_power(2,10)<<endl;
}