//Time Complexity - O(n+k)
//Auxilary Space - O(n+k)

#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void countingSort(int *arr,int n){
    int k=INT_MIN;
    //finding k, k=max element in array
    f(i,0,n){
        if(arr[i]>k) k=arr[i];
    }
    
    //making a count array in which we will store the frequency of the elements
    int count[k+1];
    //initializing the all the elements of count as zero
    memset(count,0,sizeof(count));

    //storing the frequency of all the elements in the count array
    //it means that, if we have array as --> 3 2 1 4 1 2 , then we can see that 1 comes 2 times, 2 comes 2 times, three comes 1 time and 4 comes 1 time.
    //So the count array will look like ->  
                            //Count array->
                            //              index 0 1 2 3 4
                            //              value 0 2 2 1 1
    
    f(i,0,n){
        count[arr[i]]++;
    }
    //now we will add the previous value of count to the current value, so for a particular index in count we will know how many elements are before it.
                            // Count array->
                            //              index 0 1 2 3 4
                            //              value 0 2 4 5 6
    //So now we know that, before 1 there are zero elements, before 2 there are 2 elements and so on..
    f(i,1,k+1){
        count[i]+=count[i-1];
    }

    //temporary array to store elements
    int b[n];
    //so now we will traverse form n-1 to 0 in the original array, and now we want to fix the elements on their respective indexes in the sorted array.
    //we are traversing n-1 to 0 to maintain the stability,stability means..if there is a element which occurs more than once, then the one which occurs later in the original array will be set in the sorted array after the element which comes earlier in the original array.
    for(int i=n-1;i>=0;i--){
        b[--count[arr[i]]]=arr[i];
    }
    f(i,0,n){
        arr[i]=b[i];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n) cin>>arr[i];
    countingSort(arr,n);
    f(i,0,n) cout<<arr[i]<<" ";
}