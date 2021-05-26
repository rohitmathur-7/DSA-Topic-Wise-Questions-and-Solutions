/*
    Ques: Given number n, calculate its factorial.
    Input Format
    Single line containing an integral value N.

    Constraints
    1<=N<=100

    Output Format
    Print the integral value denoting factorial of 'N'.

    Sample Input
    3
    Sample Output
    6
    Explanation
    Factorial of 3 = (321) = 6

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;

void multiply(ll *arr,ll no,ll &num){
    ll carry=0;
    f(i,0,num){
        ll product=arr[i]*no+carry;
        arr[i]=product%10;
        carry=product/10;
    }

    while(carry){
        arr[num]=carry%10;
        carry=carry/10;
        num++;
    }

}

void big_fact(ll n){

    ll arr[1000];
    f(i,0,1000){
        arr[i]=0;
    }

    arr[0]=1;
    arr[1]=1;
    ll num=1;

    f(i,2,n+1){
        multiply(arr,i,num);
    }
    
    for(ll i=num-1;i>=0;i--){
        cout<<arr[i];
    }
    cout<<endl;

}


int main(){
    ll n;
    cin>>n;
    big_fact(n);

    return 0;
}
