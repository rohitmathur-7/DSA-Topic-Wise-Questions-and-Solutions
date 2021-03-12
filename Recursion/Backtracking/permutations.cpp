//QUES: given a string, print all the permutation possible of the given string.
//ex: string ="abc", permutations: "abc","acb","bac","bca","cab","cba".

#include<bits/stdc++.h>
using namespace std;

void permutations(char *input,int i){
    //base case
    if(input[i]=='\0'){
        cout<<input<<endl;
        return;
    }
    //rec case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        permutations(input,i+1);
        //Backtracking - To restore the array as it was.(We are doing this bcz in recursion array are passed by refrence, so due to that whenever we are swapping elements..it actually is swapping the elements in the original array, which leads to getting wrong ans.So by doing this we are basically reversing the swapping so that we can get our original array back!)
        swap(input[j],input[i]);
    }
    // return;
}


int main(){
    char input[100];
    cin>>input;
    cout<<"OUTPUT: "<<endl;
    permutations(input,0);
    return 0;
}