/*
    Ques: https://codeforces.com/contest/1244/problem/C
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
ll x=-1,y=-1,GCD;

ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}

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

ll multiplicative_modulo_inverse(ll a,ll m){
    if(gcd(a,m)==1){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        return (x+m)%m;
    }
    return -1;
}

//METHOD 1 - using linear diophantine equation(Incomplete)  //Giving TLE on test case 4
// int main(){
//     ll n,p,w,d,z;
//     cin>>n>>p>>w>>d;
//     ll g=gcd(w,d);
//     extendedEuclidAlgorithm(w,d);
//     ll k=p/g;
//     // cout<<"x: "<<x<<" y: "<<y<<" k: "<<k<<endl;
//     if(p%g!=0) cout<<-1<<endl;
//     //win all the matches, but still points are less than p
//     else if(n*w<p) cout<<-1<<endl;
//     else{
//         x=x*k;
//         y=y*k;
//         z=n-(x+y);
//         bool xx=false,yy=false,zz=false,ans=false;
//         if(x<0 || x>n) xx=true;        
//         if(y<0 || y>n) yy=true;        
//         if(z<0 || z>n) zz=true;    

//         if(!xx && !yy && !zz) cout<<x<<" "<<y<<" "<<z<<endl;
//         else{
//             ll xt,yt;
//             ll dg=d/g,wg=w/g;
//             ll t=1;
//             while(!ans){
//                 xt=x+dg*t;
//                 yt=y-wg*t;
//                 z=n-(xt+yt);
//                 // cout<<xt<<" "<<yt<<" "<<z<<endl;
//                 if(xt>0 && xt<n) xx=false;
//                 if(yt>0 && yt<n) yy=false;
//                 if(z>0 && z<n) zz=false;
                
//                 if(!xx && !yy && !zz){
//                     ans=true;
//                     // cout<<"ans: "<<endl;
//                     cout<<xt<<" "<<yt<<" "<<z<<endl;
//                 }
//                 t++;
//             }
//         }   
//     }
//     return 0;
// }


//METHOD 2 - Using Multiplicative modulo inverse

/*
    Explanation - 
    x*w + y*d = p
    g=gcd(w,d)
    -so we can re-write the eq as ->    g(x*(w/g) + y*(d/g)) = p 
    -This tells us that p is a multiple of g.So p%g must be equal to 0.
    -if p%g!=0, then print -1
    -Now suppose w'=w/g, d'=d/g, p'=p/g
    - eq now is -> xw' + yd' = p'
    -Now we have 2 variables x and y, so we will try to find out one of them,
    -here we will try to find out y by taking mod with w' on whole eq., bcz of taking mod with w'..our mterm xw' will reduce3 to zero, and the eq left will be -> (yd')%w' = (p')%w'
    -Our eq is -> (y%w)=((p')%w'/d'%w') now let , d'' = (d'%w') and p'' = (p'%w')
    eq -> y%w = (p''/d'')  => (p'')*multiplicativeModInverse(d'')
    From this we will find out y,and we will substitue that in our 1st eq. and we will find out x.
    -Now as we did w/g and d/g, that is we are dividing both by their GCD, this will make w and d coprime with each other and that is why the value of x and y we get will be the smallest possible value of ax and y among all other values.
    -We will check if x+y>n, if it is true then print -1,also check if x<0, then also prine -1.
    -Prine x,y,z in the end.
*/

int main(){
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll g=gcd(w,d);
    if(p%g!=0) cout<<-1<<endl;
    else if(n*w<p) cout<<-1<<endl;
    else{
        w/=g;
        d/=g;
        d%=w;
        p/=g;
        y=(p%w)*multiplicative_modulo_inverse(d,w);
        y%=w;
        x=(p-y*d)/w;
        if(x+y>n) cout<<-1<<endl;
        else if(x<0) cout<<-1<<endl;
        else{
            ll z=n-(x+y);
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
    }
}