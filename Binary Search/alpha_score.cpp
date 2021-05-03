/*
Ques: Alpha Score
You are climbing up using stairs where a number is written on each stair. At each step we define the alpha score as sum of all the numbers previously seen on the stairs which are smaller than the present number. Alpha score of the whole journey is defined as the sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.

Input Format
First line contains a single integer n denoting the number of stairs. Next line contains n space separated integers denoting the numbers written on stairs.

Constraints
1 <= n <= 10^5 Every number written on stair lies between [0,10^9]

Output Format
Single integer denoting the alpha score of the journey modulus 1000000007.

Sample Input
5
1 5 3 6 4
Sample Output
15

*/


#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0;i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
#define mod 1000000007
using namespace std;

ll merge(ll *arr,ll s,ll mid,ll e){
    // cout<<"s: "<<s<<" mid: "<<mid<<" e: "<<e<<endl;
    ll n1=mid-s+1;
    ll n2=e-mid;
    ll left[n1],right[n2];
    // cout<<"Left: "<<endl;
    f(i,0,n1){
        left[i]=arr[s+i];
        // cout<<left[i]<<" ";
    }
    // cout<<endl;
    // cout<<"Right: "<<endl;
    f(i,0,n2){
        right[i]=arr[mid+1+i];
        // cout<<right[i]<<" ";
    }
    // cout<<endl;
    ll i=0,j=0,k=s,ans=0;
    while(i<n1 && j<n2){
        if(left[i] < right[j]){
            ans+=(left[i]*(n2-j));
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++,k++;
    }

    while(j<n2){
        arr[k]=right[j];
        j++,k++;
    }
    // cout<<"ans: "<<ans<<endl;
    return ans;
}


ll mergeSort(ll *arr,ll s,ll e){
    ll ans=0;
    if(e>s){
        ll mid=(s+e)/2;
        ans+=mergeSort(arr,s,mid);
        ans+=mergeSort(arr,mid+1,e);
        ans+=merge(arr,s,mid,e);
    }
    return ans;
}


int main(){
    ll n;
    cin>>n;
    ll arr[n];
    scana(arr);
    cout<<(mergeSort(arr,0,n-1)%mod)<<endl;
    // printa(arr);

    return 0;
}