/*
    Ques: https://codeforces.com/problemset/problem/803/F


    Explanation:
    ------------

    In this ques we want to calculate the number of coprime subsequences(which means that gcd of all elements is 1).

    So lets work in the reverse direction and lets take all the subsequences as our answer,
    now what we will do is we will iterate from 1 to N, and for every prime number we will first find the count of numbers wich our divisible by it and that are in the given array.
    ex: if array is 2 3 4 5 4, then for 2 the count will be 3(bcz 2 comes ones and 4 cmes twice).
    Now we will calculate the number of subsequences we can generate from this which is (2^cnt)-1.
    And then we will subtract this value from our answer(which is equal to number of all subsequences for now).
    We will do this for all prime number in the range 1 to N.

    Now if you notice supppose for a number 6 which is divisible by both 2 and 3, we are subtracting it 2 times from our answer, so to compensate that we will add the subsequences of 6.
    Suppose there was 10 in our array too, then we would have subtrated it again 2 time from our ans, bcz 2 and 5 both divide it..So we would have to add its subsequences in our ans.

    This is basically based on Inclusiuon-Exclusion principle.
    And also now if you see, we are subtracting the subsequences of numbers which are square-free number with an odd number of prime factors(mobius value -1) and we are adding those numbers which are square-free number with an even number of prime factors(mobius value 1).

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
const ll N = 100005;
ll num[N],prime_count[N],mobius[N];

void mobius_function(){

    f(i,1,N){
        num[i]=1;
    }
    f(i,2,N+1){
        if(prime_count[i]) continue;
        for(ll j=i;j<=N;j+=i){
            prime_count[j]++;
            num[j]*=i;
        }
    }

    f(i,1,N){
        if(num[i]==i){
            if(prime_count[i]%2!=0) mobius[i]=-1;
            else mobius[i]=1;
        }
        else mobius[i]=0;
    }
    return;
}


int main(){
    ll n;
    cin>>n;
    ll arr[n];
    ll freq[N]={0};
    mobius_function();
    f(i,0,n){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    //calc power of 2
    ll p2[N];
    p2[0]=1;
    f(i,1,N){
        p2[i]=p2[i-1]*2;
        p2[i]%=mod;
    }

    ll ans=0;

    f(i,1,N){
        ll cnt=0;
        for(ll j=i;j<N;j+=i){
            cnt+=freq[j];
        }
        ll total_subsequences=p2[cnt]-1;
        ans+=(mobius[i]*total_subsequences);
        ans%=mod;
    }
    ans+=mod;
    cout<<ans%mod<<endl;
    return 0;
}