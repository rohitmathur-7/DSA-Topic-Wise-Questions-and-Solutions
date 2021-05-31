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

void buildTree(int *a,int *tree,int s,int e,int index){
    //base case
    if(s==e){
        tree[index]=a[s];
        return;
    }
    //rec case
    int mid=(s+e)/2;
    //left subtree
    buildTree(a,tree,s,mid,2*index);
    //right subtree
    buildTree(a,tree,mid+1,e,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}              

int main(){
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);

    int *tree=new int[4*n+1];
    buildTree(a,tree,0,n-1,1); 
    f(i,1,14){
        cout<<tree[i]<<" ";
    }
    return 0;
}