#include<bits/stdc++.h>
using namespace std;

int nth_fibonnaci(int n){
    //base case
    if(n==0 || n==1) return n;
    //recursive case
    return nth_fibonnaci(n-1) + nth_fibonnaci(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<nth_fibonnaci(n)<<endl;
}