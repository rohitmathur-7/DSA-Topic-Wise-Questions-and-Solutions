/*
    Ques: https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<int>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;

void generate_subsets(vector<int> arr,vector<int> &subset,vector< vector<int> >& res,int i){
    res.push_back(subset);

    for(int j=i;j<arr.size();j++){
        //include this element in subset
        subset.push_back(arr[j]);
        generate_subsets(arr,subset,res,j+1);
        //exclude this element from subset
        subset.pop_back();
    }

    return;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int x;
    f(i,0,n){
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;

    vector<int> subset;
    vector< vector<int> > res;

    generate_subsets(arr,subset,res,0);
    for(auto x:res){
        int sum=0;
        for(auto y:x){
            sum+=y;
        }
        if(sum==k){
            for(auto y:x){
                cout<<y<<" ";
            }    
            cout<<endl;
        }
    }
    return 0;
}


//This is the exact submission code

// void subset_util(vector<int> arr,vector<int> &subset,vector< vector<int> >& res,int i){
//     res.push_back(subset);

//     for(int j=i;j<arr.size();j++){
//         //include this element in subset
//         subset.push_back(arr[j]);
//         subset_util(arr,subset,res,j+1);
//         //exclude this element from subset
//         subset.pop_back();
//     }

//     return;
// }

// vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
// {
//     // Write your code here.
//     vector<int> subset;
//     vector< vector<int> > res;
//     subset_util(arr,subset,res,0);
//     vector< vector<int> > ans;
   
//     for(int i=0;i<res.size();i++){
//         int sum=0;
//         for(int j=0;j<res[i].size();j++){
//             sum+=res[i][j];
//         }
//         if(sum==k) ans.push_back(res[i]);
//     }
//     return ans;
// }