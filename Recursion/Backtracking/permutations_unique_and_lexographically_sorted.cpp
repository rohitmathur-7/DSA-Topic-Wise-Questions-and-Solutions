//QUES: given a string, print all the permutation possible of the given string.
//Also we want only unique permuatations and in lexographically sorted order!

//ex: string ="abc", permutations: "abc","acb","bac","bca","cab","cba".

//To get only unique permutations and in lexographically sorted order we will use Set data structure which will help us in both the things.

#include<bits/stdc++.h>
using namespace std;

void permutations(char *input,int i,set<string> &s){ //pass set by refrence or otherwise only a copy of the set will be passed whenever a we call the recursive fnc, and the original set will remain empty due to that.

    //base case
    if(input[i]=='\0'){
        string t(input);
        s.insert(t);
        return;
    }
    //rec case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        permutations(input,i+1,s);
        //Backtracking - To restore the array as it was.(We are doing this bcz in recursion array are passed by refrence, so due to that whenever we are swapping elements..it actually is swapping the elements in the original array, which leads to getting wrong ans.So by doing this we are basically reversing the swapping so that we can get our original array back!)
        swap(input[j],input[i]);
    }
    // return;
}


int main(){
    char input[100];
    cin>>input;
    cout<<"OUTPUT: "<<endl;
    set<string> s;
    permutations(input,0,s);
    for(auto x:s){
        cout<<x<<endl;
    }
    return 0;
}