//QUES: a theif wants to rob a store, but his backpack can only carry weight upto 'C".
//      Given items of store their prices and weights.Tell the maximum amount that the theif can earn! 

#include<bits/stdc++.h>
using namespace std;

int profit(int n,int c,int *weights,int *prices){
    //base case
    if(n==0 || c==0) return 0;

    //rec case
    int inc,exc;
    int ans=0;
    inc=exc=0;

    //We can think of it like this, we start from the last, now we have 2 choice-
    //either we can inlude this element or we do not inlude this element in our ans.
    //and also we can only include this element only if the weight of that element is smaller or equal to c.

    //include
    if(weights[n-1]<=c){
        inc = prices[n-1] + profit(n-1,c-weights[n-1],weights,prices);
    }
    //exclude
    exc=profit(n-1,c,weights,prices);
    
    ans=max(inc,exc);
    return ans;
}



int main(){
    int weights[]={1,2,3,5};
    int prices[]={40,20,30,100};
    int n=4;
    int c=7;
    cout<<profit(n,c,weights,prices)<<endl;
}