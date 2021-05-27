/*
    Ques: 
    Alice is learning mathematical functions. In his assignment, teacher has asked him to evaluate 
    h(x)= f(x)+g(x) where,
    f(x)=3x2-x+10 and
    g(x)=4x3+2x2-5x+4.
    As he is weak in mathematics, help him finish this task.

    Hint: Since X is large, you need to work with Big Integers!

    Input Format
    Single line containing an integral value denoting the value of x.

    Constraints
    0<=x<=10^50

    Output Format
    Print integral value denoting value of h(x).

    Sample Input
    1
    Sample Output
    17
    Explanation
    f(1)=3-1+10=12 g(1)=4+2-5+4=5 h(1)=f(1)+g(1)=12+5=17
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

string multiply_strings(string s1,string s2){

    ll n1=s1.size();
    ll n2=s2.size();

    if(n1==0 || n2==0) return "0";

    ll i_n1=0,i_n2=0,ns1,ns2;
    vl res(n1+n2,0);

    for(ll i=n1-1;i>=0;i--){
        ns1=s1[i]-'0';
        i_n2=0;
        ll carry=0;
        for(ll j=n2-1;j>=0;j--){
            ns2=s2[j]-'0';
            ll sum=ns1*ns2+res[i_n1+i_n2]+carry;
            carry=sum/10;
            res[i_n1+i_n2]=sum%10;

            i_n2++;
        }
        if(carry>0) res[i_n1+i_n2]+=carry;

        i_n1++;
    }
    
    ll i=res.size()-1;
    while(i>=0 && res[i]==0) i--;

    if(i==-1) return "0";

    string s="";
    while(i>=0){
        s+=to_string(res[i]);
        i--;
    }
    
    return s;

}

string add(string s1,string s2){
    ll n1=s1.size();
    ll n2=s2.size();

    ll mn=min(n1,n2);
    ll mx=max(n1,n2);
    string smx,smn;
    if(n1==mx){
        smx=s1;
        smn=s2;
    }
    else{
        smx=s2;
        smn=s1;
    }

    vl res(mx,0);
    ll carry=0;
    ll c=0;
    ll d=mx-mn;
    for(ll i=mx-1;i>=0;i--){
        if(c<mn){
            ll sum=(smn[i-d]-'0')+(smx[i]-'0')+carry;
            carry=sum/10;
            res[i]=sum%10;
        }
        else{
            res[i]=smx[i]-'0'+carry;
            carry=res[i]/10;
        }
        c++;
    }

    string s=""; 
    ll left;
    if(carry>0){
        left=carry;
        s+=to_string(left);
    }
    ll i=0;
    while(i<mx){
        s+=to_string(res[i]);
        i++;
    }   
    
    return s;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}

string subtract(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}


int main(){

    string x,sq,cube;
    cin>>x;
    sq=multiply_strings(x,x);
    cube=multiply_strings(x,sq);

    sq=multiply_strings("5",sq);
    cube=multiply_strings("4",cube);
    x=multiply_strings("6",x);
    
    string ans=add(sq,cube);
    ans=subtract(ans,x);
    ans=add(ans,"14");

    cout<<ans<<endl;

    return 0;
}