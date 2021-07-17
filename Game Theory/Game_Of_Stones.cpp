/*
    Ques:
    -----
    Two players (numbered 1 and 2) are playing a game with stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:

    In a single move, a player can remove either 2,3,or 5 stones from the game board. If a player is unable to make a move, that player loses the game. Given the number of stones, find and print the name of the winner (i.e.,First or Second) on a new line. Each player plays optimally, meaning they will not make a move that causes them to lose the game if some better, winning move exists.

    NOTE :- Try solving the problem using property of Grundy numbers to learn the concept. Original Problem :- Hackerrank

    Input Format
    The first line contains an integer T, denoting the number of test cases. Each of the subsequent lines contains a single integer n , denoting the number of stones in a test case.

    Constraints
    1 <= T <= 100
    1 <= N <= 100

    Output Format
    On a new line for each test case, print First if the first player is the winner; otherwise, print Second.

    Sample Input
    8
    1
    2
    3
    4
    5
    6
    7
    10
    Sample Output
    Second
    First
    First
    First
    First
    First
    Second
    First

    Explanation:
    ------------
    Just calculate the Grundy Number of N.

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0,i<n;i++) cout<<arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
map<ll,ll> m;

ll MEX(set<ll> st){
    ll mx=0;
    while(st.find(mx)!=st.end()) mx++;
    return mx;
}

ll grundy(ll n){
    //base case
    if(n==0) return 0;
    if(n==1) return 0;

    if(m.count(n)) return m[n];

    set<ll> st;

    if(n-2>=0) st.insert(grundy(n-2));
    if(n-3>=0) st.insert(grundy(n-3));
    if(n-5>=0) st.insert(grundy(n-5));
    
    ll mx=MEX(st);
    m[n]=mx;
    return mx;
}
 
int main(){
 
    w(t){
        ll n;
        cin>>n;
        if(grundy(n)!=0) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
     
    return 0;
}