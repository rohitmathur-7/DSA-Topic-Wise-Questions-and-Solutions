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
                     
//************************
//Important functions
                      
//gcd
/*
ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}
*/
                        
//extended euclid algorithm
/*
void extendedEuclidAlgorithm(ll a,ll b){
    //base case
    if(b==0){
        x=1;y=0;
        GCD=a;
        return;
    }
    //rec case
    extendedEuclidAlgorithm(b,a%b);
    ll cx=y;
    ll cy=x-((a/b)*y);
                    
    x=cx;
    y=cy;
}
*/
                        
//to compute a^b
/*
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
*/
 
//to find multiplicative modulo inverse
/*
void multiplicative_modulo_inverse(ll a,ll m){
    if(gcd(a,m)==1){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        cout<<(x+m)%m<<endl;
    }
    else cout<<
Multiplicative modulo inverse is not possible!
<<endl;
}
*/
 
//prime sieve
/*
void prime_sieve(ll *p){
    for(ll i=3;i<=100000;i+=2) p[i]=1;
 
    for(ll i=3;i<=100000;i+=2){
    if(p[i]==1){
        for(ll j=i*i;j<=100000;j+=i){
            p[j]=0;
        }
        }
        }
    p[2]=1;
    p[1]=0;p[0]=0;
}
*/
//************************

// ** T.C - O(5n)  S.C - O(1) ** 
int *findTwoElement_most_optimal_approach(int *arr, int n){
    int xr=0;
    //xoring the elements of array and elements from 1 to n.
    for(int i=0;i<n;i++){
        xr^=arr[i];
        xr^=(i+1);
    }

    //now xr here represents x^y.(x^y=xr)
    bool g=true;
    int c=0,pos;
    while(1){
        if(xr&(1<<c)){
            pos=c;
            break;
        }
        c++;
    }
    // cout<<"pos: "<<pos<<endl;
    //distributing elements in 2 buckets
    int xr1=0,xr2=0;
    for(int i=0;i<n;i++){
        if(arr[i]&(1<<pos)){
            xr1^=arr[i];
        }
        else{
            xr2^=arr[i];
        }

        if((i+1)&(1<<pos)){
            xr1^=i+1;
        }
        else{
            xr2^=i+1;
        }
    }


    int *ans=new int(2);
    for(int i=0;i<n;i++){
        if(arr[i]==xr1){
            ans[0]=xr1;
            break;
        }
        else if(arr[i]==xr2){
            ans[0]=xr2;
            break;
        }
    }

    if(ans[0]==xr1) ans[1]=xr2;
    else ans[1]=xr1;

    return ans;
}
 
int main(){
    
    int n;cin>>n;
    int arr[n];
    f(i,0,n){cin>>arr[i];}
    int *ans = findTwoElement_most_optimal_approach(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
     
    return 0;
}