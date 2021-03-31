/*
    QUES: given a number, find the square root of it.
*/


#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(log(n) + p)
    log(n) for taking out the aquare root, and p for taking out the floating point number.
    but as p will be very small, so Time Complexity - O(log(n))
*/

//brute force is expensive(O(sqrt(n))) that's why we are using binary search to take out the square root of the number.

float square_root(int n,int p){
    int s=0;
    int e=n;
    float ans;
    while(s<=e){
        int mid=(s+e)>>1;
        if(mid*mid == n) return mid;
        else if(mid*mid < n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    //floating point part
    //brute force
    float inc=0.1;
    for(int times=1;times<=p;times++){
        while(ans*ans<=n){
            ans+=inc;
        }
        //at this point we overshoot the value
        ans-=inc;
        inc/=10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int precison;
    cin>>precison;
    cout<<square_root(n,precison)<<endl;
}