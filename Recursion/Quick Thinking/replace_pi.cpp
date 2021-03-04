// Ques: given a char array,replace all occurences of pi with 3.14, ex: string ="abcpi" output=abc3.14

#include<bits/stdc++.h>
using namespace std;

void replace_pi(char arr[],int i){
    //base case
    if(arr[i]=='\0' || arr[i+1]=='\0') return; //if current element is '\0' or the next is '\0' then return.

    //rec case
    if(arr[i]=='p' && arr[i+1]=='i'){  //if current char is 'p' and the next is 'i', then we have found pi
        int j=i+2; // now when we will replace pi with 3.14,we can see that pi takes 2 places and 3.14 takes 4 places.So to fit in 3.14 inplace of pi, we have to shift the elements starting from i+2 to the right, so that we can make room for 3.14 to fit.

        while(arr[j]!='\0'){ //take your j to the end,i.e j will be at the '\0' character
            j++;
        }

        //now traverse back from j(which is pointing to the '\0' char) till i+2, and we are doing this bcz we want to shift our elements from i+2 index till the end towards right, so that we can make room for 3.14.
        while(j>=i+2){
            arr[j+2]=arr[j];
            j--;
        }

        //now just assign the value 3.14
        arr[i]='3';arr[i+1]='.';arr[i+2]='1';arr[i+3]='4';

        //now call the function again, but from the index i+4, coz 3.14 ends at index i+3, and we have to search for another 3.14 in further parts of the array too!
        replace_pi(arr,i+4);
    }

    //this is the normal recursive call, where we just pass in the increased index.
    replace_pi(arr,i+1);
    return;
}

int main(){
    char arr[100000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    replace_pi(arr,i);
    cout<<arr<<endl;
}