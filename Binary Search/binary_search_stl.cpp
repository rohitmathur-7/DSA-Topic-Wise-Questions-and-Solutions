#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    //to check if a element is present in a array or not
    //we have a func in STL which is binary_search, which return true if the element is present and false if element is not present
    bool present = binary_search(arr,arr+n,key);
    if(present) cout<<"Element is present!"<<endl;
    else cout<<"Element is absent!"<<endl;

    //lower_bound fnc in stl returns the address to the postiton that is >= to key.(greater than or equal to)
    auto lb=lower_bound(arr,arr+n,key);
    cout<<"Lower bound: "<<(lb-arr)<<endl;

    //upper_bound fnc in stl returns the address to the postiton that is > to key.(strictly greater)
    auto ub=upper_bound(arr,arr+n,key);
    cout<<"Upper Bound: "<<(ub-arr)<<endl;

    //to calculate the frequency of a element in a array we can just subtract the upper bound and lower bound , and we will get the frequency of the element

    int frequency = ub-lb;
    cout<<"Frequency: "<<frequency<<endl; 
    // this method can also be used to check if a element is present in array or not, bcz if the element is not present than the frequency will be zero!

    return 0;
}