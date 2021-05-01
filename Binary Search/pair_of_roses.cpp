/*
Ques - Pair of roses
A guy has a limited amount of money that he can spend on his girlfriend. So he decides to buy two roses for her. Since roses are of varying sizes, their prices are different. He wishes to completely spend that fixed amount of money on buying roses for her.
As he wishes to spend all the money, he should choose a pair of roses whose prices when summed up are equal to the money that he has.
Help him choose such a pair of roses for his girlfriend.

NOTE: If there are multiple solutions print the solution that minimizes the difference between the prices i and j. After each test case, you must print a blank line.

Input Format
The first line indicates the number of test cases T.
Then, in the next line, the number of available roses, N is given.
The next line will have N integers, representing the price of each rose, a rose that costs less than 1000001.
Then there is another line with an integer M, representing how much money he has.
There is a blank line after each test case.

Constraints
1≤ T ≤100
2 ≤ N ≤ 10000
Price[i]<1000001

Output Format
For each test case, you must print the message: 'He should buy roses whose prices are i and j.’, where i and j are the prices of the roses whose sum is equal do M and i ≤ j. You can consider that it is always possible to find a solution. If there are multiple solutions print the solution that minimizes the difference between the prices i and j.

Sample Input
2
2
40 40
80

5
10 2 6 8 4
10
Sample Output
He should buy roses whose prices are 40 and 40.
He should buy roses whose prices are 4 and 6.
Explanation
Find two such kinds of price of roses which has sum up to equal to The guy'sMoney.
*/

//Time Complexity - O(nlogn)

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define mod 1000000007
using namespace std;

int main(){
    w(t){
        ll n;
        cin>>n;
        ll arr[n];
        f(i,0,n) cin>>arr[i];
        ll m;
        cin>>m;
        sort(arr,arr+n);
        ll x,y,cdiff,d=LLONG_MAX;
        f(i,0,n){
            ll cdiff=m-arr[i];
            if(binary_search(arr+i+1,arr+n,cdiff)){
                if(cdiff<d){
                    x=min(arr[i],cdiff);
                    y=max(arr[i],cdiff);
                    d=cdiff;
                }
            }
        }
        cout<<"He should buy roses whose prices are "<<x<<" and "<<y<<"."<<endl;
    }
    return 0;
}