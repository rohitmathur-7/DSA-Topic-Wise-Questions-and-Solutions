/*
    Ques:
    Mancunian and his arch-enemy Liverbird are playing a game. They have a multiset of positive integers available and they alternate turns. Mancunian always starts.

    Each move consists of choosing some prime number p and then choosing a non-empty subset of the multiset such that each element of the subset is divisible by p. Then, the player divides each member of the subset by some non-zero power of p.

    Note that the element must be divisible by pa if you are performing division by pa For example, if the chosen prime is 3 then 18 is divisible by 9 but not by 27 Also, it is not necessary to divide each element of the subset with the same power of p.

    Input Format
    The first line contains a single integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the number of elements in the multiset S The second line of each test case contains N integers denoting the elements of the multiset.

    Constraints
    1≤T≤20 1≤N≤10000 1 <= each element <= 10^6

    Output Format
    For each test case, print the name of the winning player in a new line.

    Sample Input
    2
    4
    1 2 3 5
    4
    3 18 2 2
    Sample Output
    Mancunian
    Liverbird
    Explanation
    Consider the first case. In the first move, Mancunian chooses one prime from the set {2, 3, 5}. If he chooses 2, then he has to choose the subset containing only the value 2 from the array and divide it by 2. In the next move, Liverbird chooses one of the primes {3, 5}. If he chooses 3, then he has to choose the subset containing only the value 3 from the array and divide it by 3. In the last move, Mancunian repeats the same with the prime 5. Liverbird cannot make a move and he loses. All other possible paths of the game are analogous to this one.



    READ THIS - https://www.geeksforgeeks.org/combinatorial-game-theory-set-2-game-nim/

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

void prime_factors(ll n){
    ll count;	
    f(i,2,sqrt(n)+1){
        if(n%i==0){
            count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            m[i]+=count;
        }
    }
    if(n!=1){
        m[n]++;
	}
}

int main(){
 
    w(t){
        ll n;
        cin>>n;
        ll arr[n];
        f(i,0,n){
            cin>>arr[i];
            prime_factors(arr[i]);
        }   
        ll xr;
        ll c=0;
        for(auto x:m){
            if(c==0) xr=x.second;
            else xr^=x.second;
            c++;
        }
        if(xr!=0) cout<<"Mancunian"<<endl;
        else cout<<"Liverbird"<<endl;
        m.clear();
    }
     
    return 0;
}