// QUES: Given n friends who want to go to a party on bikes.Each guy can go as single or as couple.
//       Find the number of ways in which n friends can go to a party.

#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    //base case
    if(n==0 || n==1) return 1;
    //rec case
    return n*fact(n-1);
}

int nCr(int n,int r){
    int ans=((fact(n))/(fact(r)*(fact(n-r))));
    return ans;
}

int friends_pairing(int n){
    //base case
    if(n<=1) return 1; //n==0 also return 1, bcz no one going is also a way.
    //rec case
    // f(n) = 1*f(n-1) + nCr*f(n-2)
    return friends_pairing(n-1)+(nCr(n-1,1)*friends_pairing(n-2));
}


int main(){
    int n;
    cin>>n;
    cout<<friends_pairing(n)<<endl;
}