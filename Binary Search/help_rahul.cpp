/*
QUES: Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

Hint - Think Binary Search!

Input Format
The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

Constraints
Output Format
Output the index of number in the array to be searched. Output -1 if the number is not found.

Sample Input
5
4
5
1
2
3
2
Sample Output
3
Explanation
The given rotated array is [4, 5, 1, 2, 3]. The element to be searched is 2 whose index is 3.
*/




#include<bits/stdc++.h>
using namespace std;

int find_key(int *arr,int n,int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid] == key) return mid;
        else if(arr[s] <= arr[mid]){ //it means that the array part from s to mid is sorted
            if(key>=arr[s] && key<=arr[mid]) e=mid-1; //key is in left part
            else s=mid+1; //key is in right part
        }
        else{  //this else means, arr[e]>=arr[mid] ,which means that our array is sorted from mid to e.
            if(key>=arr[mid] && key<=arr[e]) s=mid+1; //key is in right part
            else e=mid-1; //key is in left part
        }
    }
    return -1; //if the key is not present then return -1.
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cin>>key;
    cout<<find_key(arr,n,key)<<endl;
    return 0;
}