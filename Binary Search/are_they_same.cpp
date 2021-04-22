/*
Ques:
This year when tourist visited India for codsule 2019. He and Rajat started discussing few problems on divide and conquer. tourist asked Rajat that if you have 2 strings s1 and s2 can you find if they are equivalent. Rajat then asked the condition for being equivalent to which tourist replied

Two strings a and b of equal length are called equivalent in one of the two cases:

They are equal.
If we split string a into two halves of the same size a1 and a2, and string b into two halves of the same size b1 and b2, then one of the following is correct:
a1 is equivalent to b1, and a2 is equivalent to b2
a1 is equivalent to b2, and a2 is equivalent to b1
Rajat quickly solved the problem can you?

Input Format
First line is number of test cases t Then follow two strings each of same length

Constraints
1 <= test cases <= 10 1 <= string length <= 50000

Output Format
print "YES" if they are "equivalent" and "NO" if they are not

Sample Input
3
ababa
baaba
ab
ba
abc
abc
Sample Output
NO
YES
YES
Explanation
test case 1 : - you cannot split the string into two halves of same size and s1 != s2 hence they are not same test case 2 :- split ab as a and b and ba as b and a then conditon is fulfilled test case 3 :- they are already same
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;


bool solve(string s1,string s2,ll sze1,ll sze2){
    if(sze1!=sze2) return false;

    if(s1==s2) return true;
    else{
        if(sze1%2==0 && sze2%2==0){
            string a1="",a2="",b1="",b2="";
            ll mid=(sze1-1)/2;
            f(i,0,mid+1){
                a1+=s1[i];
                b1+=s2[i];
            }
            f(i,mid+1,sze1){
                a2+=s1[i];
                b2+=s2[i];
            }
            ll a1_s=a1.size(),a2_s=a2.size(),b1_s=b1.size(),b2_s=b2.size();
            if(solve(a1,b1,a1_s,b1_s) && solve(a2,b2,a2_s,b2_s)) return true;
            if(solve(a1,b2,a1_s,b2_s) && solve(a2,b1,a2_s,b1_s)) return true;
            return false;
        }
        else return false;
        
    }
}

int main(){
    w(t){
        string s1,s2;
		cin>>s1>>s2;
        ll sze1=s1.size(),sze2=s2.size();

        if(solve(s1,s2,sze1,sze2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}