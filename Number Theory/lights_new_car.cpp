/*
    Ques: 
    -----

    Light wants to purchase a new car.The price of the new car is A.After each passing day,the price of the car becomes A times the price on the previous day.However,B days have passed since car launch.Light dosen't know the price of the car on the Bth day, he has asked for your help.
    Your task is to tell the price of the car on the Bth day.Since the can be a very large number,please tell him the price modulo 10^9+7/

    Input: 
    1st line for test case
    2nd line will contain 2 integers A and B seprated by space

    Constraints:
    1<= T <= 10
    1 <= A,B <= 10^100000
    A%(10^9+7) != 0

    Output:
    output t lines corresponding to each test case.

    Sample Input:
    4
    3 2
    4 5 
    7 4
    34534985349875439875439875349875 93475349759384754395743975349573495

    Sample Output:
    9
    1024
    2401
    735851262


    Approach:
    ---------
    We basically want to calculate (A^B)%p      (p->prime number)
    Now we can rewrite B as, B=a(p-1)+b
    ->  (A^(a(p-1)+b))%p
    ->  (A^(a(p-1))%p).((A^b)%p)

    Now there is a theorem called Fermet's Little Theorem which is - 
        (a^(p-1))%p = 1           (where p is a prime number)
    
    So using this in our equation-
    -> (A^(a(p-1))%p) will become 1^a, so eq. becomes - (A^b)%p
    Now we can write b as, b=B%(p-1)
    ->  (A^(B%(p-1)))%p

    Now as we have the power of A as B%(p-1), which means that B will be <=p-1, and as p<=10^9, [B%(p-1)<=10^9]
     So now we can write the eq as- (A%p)^(B%(p-1)), A%p can also be calculated.
     So now A<p and B<p, 
     So now we can calculate A^B using fast modulo exponentiation.

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

ll stringToInt(string a,ll m){
    ll ans=0;
    f(i,0,a.size()){
        ans=(ans*10)%m + (a[i]-'0');
        ans%=m;
    }
    return ans;
}

//log(n) time
ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=((ans%mod)*(a%mod))%mod;
        }
        a=((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return (ans%mod);
}

//log(n) time
ll power(ll x,ll y, ll m){
    //base case
    if(y==0) return 1;
    //recursive x^(y/2)
    cout<<"power("<<x<<","<<y/2<<")"<<endl;
    ll smallpower=power(x,y/2,m);
    smallpower%=m;
    smallpower=(smallpower*smallpower)%m;
    if(y&1) return x*smallpower%mod;
    return smallpower;
}



int main(){
    w(t){
        string a,b;
        cin>>a>>b;
        ll x=stringToInt(a,mod);
        ll y=stringToInt(b,mod-1);
        ll ans=fast_modulo_exponentation(x,y);  //use either this
      //ll ans=power(x,y,mod); //or this
        cout<<ans<<endl;
    }



    return 0;
}