/*
    Ques:
    Vivek likes to solve mathematical problems. So, Dheer tries to challenge him with a problem. But Vivek is quite busy these days, So he asks for your help.

    The problem is as follows: You are given an integer q which denotes the number of queries. For each query, You are given an integer n. You have to find the result of number n.

    The result of a number n is defined as the sum of even divisors of n minus the sum of odd divisors of n.

    More Formally, result = (Sum of even divisors of n) - (Sum of odd divisors of n)

    A divisor of a number n is defined as a positive integer i such that n is divisible by i.

    Input Format
    First line of input contains an integer q denoting the number of queries. After that q lines follow, Each line consists an integer n for which you have to find the value of result.

    Note: Use fast input output as input is quite large;

    Constraints
    1 <= q <= 100000 1 <= n <= 100000

    Output Format
    You have to print q lines, where the output of the ith line is the result of the ith query.

    Sample Input
    2
    3
    6
    Sample Output
    -4
    4
    Explanation
    For n = 3 : Odd Divisors of 3 are 1 and 3 So , Sum of odd divisors = 1 + 3 = 4 3 has no even divisors So , Sum of even divisors = 0 Therefore result = Sum of even divisors - Sum of odd Divisors = 0 - 4 = -4

    Similarly For n = 6 : Odd Divisors of 6 are 1 and 3 So , Sum of odd divisors = 1 + 3 = 4 Even Divisors of 6 are 2 and 6 So , Sum of even divisors = 2 + 6 = 8 Therefore result = Sum of even Divisors - Sum of odd Divisors = 8 - 4 = 4

    Explanation -
    First calculate the sum of all divisors of n, then divide this whole sum by (2^p+1)-1 bcz all the even divisors will only be contributed by 2(as 2 is the only even prime number)...this is the value of sum of all odd divisors that we just obtained.
    Now subtract the sum of all odd divisors from total sum and you will get sum  of all even divisors.
    Now just subtract sum of all even divisors and sum of all odd divisors.

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
ll arr[100000000]={0};
                   
//to compute a^b
ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}

void prime_factors_optimized_approach(ll n){
    ll count;
    map<ll,ll> m;
    ll nn=n,sum=1;
    ll sEven=0,sOdd=0,pe=0;
    f(i,2,sqrt(n)+1){
        if(n%i==0){
            count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            m[i]=count;
        }
    }
    if(n!=1){
        m[n]=1;
    }    

    for(auto x:m){
        if(x.first==2) pe=x.second;
        ll p=(fast_modulo_exponentation(x.first,x.second+1)-1);
        sum*=(p/(x.first-1));
    }

    ll tmp = fast_modulo_exponentation(2,pe+1)-1;

    sOdd=sum/tmp;

    sEven=sum-sOdd;

    ll diff = sEven-sOdd;

    arr[nn]=diff;

}
 
int main(){
    arr[1]=-1;
    f(i,2,100001){
        prime_factors_optimized_approach(i);
    }

    w(q){
        ll n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
     
    return 0;
}