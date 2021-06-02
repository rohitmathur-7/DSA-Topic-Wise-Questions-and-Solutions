/*
    Ques:
    Alice is given the task of finding totient φ of a positive integer n (the number of positive integers less than or equal to n that are co-prime to n). As Alice is going on a date, he asks you to write a program for this.

    Input Format
    First line of input of consists of an integer 't' denoting the number of test cases. Then 't' lines follow each containing integer values 'n' to calculate totient.

    Constraints
    1<=t<=50000 1<=n<=10^6

    Output Format
    Print 't' lines

    Sample Input
    2
    2
    3
    Sample Output
    1
    2
    Explanation
    For first test case: number co-prime to 2 which are less than 2 is '1' only.
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll> 
#define  vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;
ll tot[1000001];

void totient(){
    f(i,0,1000001){
        tot[i]=i;
    }
    
    f(i,2,1000001){
        if(tot[i]==i){
            tot[i]=i-1;
            for(ll j=2*i;j<=1000001;j+=i){
                tot[j]*=(i-1);
                tot[j]/=i;
            }
        }
    }

}

int main(){
    totient();
    w(t){
        ll n;
        cin>>n;
        cout<<tot[n]<<endl;   
    }
    return 0;
}

