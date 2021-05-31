/*
    Ques:
    Given an array, print the minimum element in the range l-r.
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

int query(int *tree,int ss,int se,int qs,int qe,int index){

    //complete overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }

    //no overlap
    if(qs>se || qe<ss){
        return INT_MAX;
    }

    //partial overlap
    int mid=(ss+se)/2;
    int left = query(tree,ss,mid,qs,qe,2*index);
    int right = query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);
}

int main(){
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);

    int *tree=new int[4*n+1];
    buildTree(a,tree,0,n-1,1); 
    // f(i,1,14){
    //     cout<<tree[i]<<" ";
    // }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l,r,1)<<endl;
    }
    
    return 0;
}