//https://www.geeksforgeeks.org/find-the-point-where-a-function-becomes-negative/

//Problem - Find the point where a monotonically increasing function becomes positive first time.


#include<bits/stdc++.h>
using namespace std;

// Let's take an example function
// as f(x) = x^2 - 10*x - 20 Note that
// f(x) can be any monotonocally increasing function
int f(int x) { return (x*x - 10*x - 20); }

int first_positive(){
    if(f(0)>0) return 0;

    bool g=false;
    int a=1;
    int high;
    while(!g){
        if(f(a)>0){
            //when we encounter the first value which gives f(a) as positive, we take it as high for binary search
            high=a;
            g=true;
            break;
        }
        else{
            a*=2; //doubling our value
        }
    }
    
    //now we will use binary search, we will take low as (high/2) because as we were doubling our values, so we definitely know that there exist no such value before high/2 which will give f(value) as positive.
    int low=high/2;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        //if we find a value which gives f(value)>0 and f(value-1)<=0, then we have found our value.
        if(f(mid)>0 && (mid==low || f(mid-1)<=0)){
            return mid;
        }

        //if f(mid) is >0, then we know that answer wont't exist after this value,so we will decrease our high value. 
        if(f(mid)>0) high=mid-1;
        //if f(mid) is <0, then we know that answer wont't exist before this value,so we will increase our low value. 
        else low=mid+1;
    }

    //if no value return +ve value, return -1
    return -1;
}

int main(){

    cout<<first_positive()<<endl;

}