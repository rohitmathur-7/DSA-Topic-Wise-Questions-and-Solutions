//QUES: https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&category[]=Binary%20Search&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazoncategory[]Binary%20Search#

#include<bits/stdc++.h>
using namespace std;

long left(vector<long long> v, long long x){
    long s=0,e=v.size()-1;
    long l_ans=-1;
    while(s<=e){
        long mid=(s+e)/2;
        if(v[mid]==x){
            l_ans=mid;
            if(v[mid-1]!=x) return mid;
            else{
                e=mid-1;
            }
        }
        else if(v[mid]<x) s=mid+1;
        else e=mid-1;
    }
    return l_ans;
}
    
long right(vector<long long> v, long long x){
    long s=0,e=v.size()-1;
    long r_ans=-1;
    while(s<=e){
        long mid=(s+e)/2;
        if(v[mid]==x){
            r_ans=mid;
            if(v[mid+1]!=x) return mid;
            else{
                s=mid+1;
            }
        }
        else if(v[mid]<x) s=mid+1;
        else e=mid-1;
    }
    return r_ans;
}

pair<long,long> solve(long long n,vector<long long> v,long long x){
    pair<long,long> ans;
    int s=0,e=v.size()-1;
    ans.first=left(v,x);
    ans.second=right(v,x);
    return ans;
}


int main(){
    long long  n;
    cin>>n;
    vector<long long> v;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        v.push_back(x);
    }
    long long x;
    cin>>x;
    pair<long,long> ans = solve(n,v,x);
    cout<<ans.first<<" "<<ans.second<<endl;
}