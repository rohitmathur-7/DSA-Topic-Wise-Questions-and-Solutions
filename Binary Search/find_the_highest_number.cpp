//QUES: https://practice.geeksforgeeks.org/problems/find-the-highest-number2259/1/?category[]=Binary%20Search&category[]=Binary%20Search&page=1&query=category[]Binary%20Searchpage1category[]Binary%20Search

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    if(a[a.size()-1]==a.size()) return a.size();
        // Code here
        int s=0;
        int e=a.size()-1;
        int ans;
        while(s<=e){
            int mid=(s+e)/2;
            if(a[mid]>a[mid+1]){
                e=mid-1;
                ans=a[mid];
            }
            else s=mid+1;
        }
     return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<solve(a);
}