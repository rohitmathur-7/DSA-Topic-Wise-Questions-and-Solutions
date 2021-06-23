/*
    Ques:
    Vivek loves to play number games with his friend Ujjawal. One day they were playing a game where one of them will speak out a positive number and the other have to tell the sum of its factors. The first one to say it correctly wins. After a while they got bored and wanted to try out a different game. Vivek then suggested about trying the reverse. That is, given a positive number 'S' , they have to find a number whose factors add up to 'S'. Realizing that this task is tougher than the original task, Vivek came to you for help. Luckily Vivek owns a portable programmable device and you have decided to burn a program to this device. Given the value of 'S' as input to the program, it will output a number whose sum of factors equal to 'S' .

    Input Format
    There are several cases . Each case of input will consist of a positive integer 'S'<= 100000 . The last case is followed by a value of 0 .

    Constraints
    0 < S <= 10000

    Output Format
    print the integer whose factors sum is equal to 'S'. Print the largest Integer whose factors sum is 'S' . If no such number exists, output '-1' .

    Sample Input
    1
    102
    1000
    0
    Sample Output
    1
    101
    -1


    Explanation: 
    Brute force it.
    iterate from 1 to 1e5+1 and calculate the sum of divisors of all numbers using the mathematical formula -  
    sum of all divisros =  (p1^(k1+1) - 1) / (p1-1) * (p2^(k2+1) - 1) / (p2-1) ....and so on
                                (where p1,p2..pn = prime factors of number n and k1,k2...kn = powers of those respective primes.)
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
// /*
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

//Method 1
// void prime_factors_optimized_approach(ll n){
//     ll count;
//     ll nn=n;
//     ll res=1;
//     f(i,2,sqrt(n)+1){
//         ll curr_sum = 1;
//         ll curr_term = 1;
//         while (n % i == 0) {
//             n = n / i;
//             curr_term *= i;
//             curr_sum += curr_term;
//         }
//         res *= curr_sum;
//     }
//      if (n >= 2) res *= (1 + n); 
//      arr[res]=nn;
// }
 
// int main(){

//     arr[1]=1;
//     f(i,2,100001){
//         prime_factors_optimized_approach(i);
//     }
    
//     ll s;
//     cin>>s;
//     while(s!=0){
//         if(arr[s]!=0) cout<<arr[s]<<endl;
//         else cout<<-1<<endl;
//         cin>>s;
//     }
     
//     return 0;
// }

//Method 2
// void prime_factors_optimized_approach(ll n){
//     ll count;
//     map<ll,ll> m;
//     ll nn=n,sum=1;
//     f(i,2,sqrt(n)+1){
//         if(n%i==0){
//             count=0;
//             while(n%i==0){
//                 n/=i;
//                 count++;
//             }
//             m[i]=count;
//         }
//     }
//     if(n!=1){
//         m[n]=1;
//     }    

//     //calculating the sum of the divisors of n
//     //(p^k+1 - 1) / (p-1) 
//     for(auto x:m){
//         ll p=(fast_modulo_exponentation(x.first,x.second+1)-1);
//         sum*=(p/(x.first-1));
//     }
//     arr[sum]=nn;
// }
 
// int main(){

//     f(i,1,100005){
//         prime_factors_optimized_approach(i);
//     }

//     ll s;
//     cin>>s;
//     while(s!=0){
//         if(arr[s]!=0) cout<<arr[s]<<endl;
//         else cout<<-1<<endl;
//         cin>>s;
//     }
 
//     return 0;
// }



//Both the methods use the same mathematical formula to calculate the sum of divisors, but the only difference is in the implementation of it.