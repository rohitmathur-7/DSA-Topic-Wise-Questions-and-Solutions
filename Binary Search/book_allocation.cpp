/*
QUES:

You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)

*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

bool canKeep(int *arr,int n,int m,int minPages){
    int students=1;
    int pages=0;
    f(i,0,n){
        if(pages+arr[i]>minPages){
            students++;
            if(students>m) return false;
            pages=arr[i];
        }
        else pages+=arr[i];
    }
    return true;
}

void solve(int *arr,int n,int m,int sum){
    //in worst case the student will read minimum 0 pages, and maximum all the pages given in the array.So will have starting point as 0 and ending point as sum of all pages.
    //and then we will use Binary Search, Now we know that are search space is b/w 0 and sum of all pages.
    //So, we will first take out mid and check if we can distribute books among m students such that the max pages they read is less than mid.And then we will just try to find minimum mid which will be our answer.
    int s=0;
    int e=sum;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(canKeep(arr,n,m,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
}

int main(){
    w(t){
        int n,m;
        cin>>n>>m;
        int arr[n];
        int sum=0;
        f(i,0,n){
            cin>>arr[i];
            sum+=arr[i];
        }
        solve(arr,n,m,sum);
    }
    return 0;
}