// QUES: given a string(char array), generate all the possible subsets of the given string.
//       ex s="abc", 
//       subsets- " " , 'a','b','c','ab','ac','bc','abc'.

//       - subsets can have non-continous parts of array too!(ex: "ac"),
//         subarrays cannot have non-continous parts of array!.
//       - Number of subsets = 2^(length of string).(2 to the power of length of the string)
//                             ex: s="abc" , length=3
//                                 subsets = 2^3 => 8(NULL subset is also counted in this!)


#include<bits/stdc++.h>
using namespace std;

void generate_subsequences(char *inp,char *out,int i,int j){
    //base case
    if(inp[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    out[j]=inp[i];

    //For evey char we can have 2 choices, either we can include it in our subset, or not include it in our subset.
    //This way we will eventually get all the possible subsets of a string!.

    //include the current char
    generate_subsequences(inp,out,i+1,j+1);
    //exclude the current char
    generate_subsequences(inp,out,i+1,j);
}

int main(){
    char inp[]="abc";
    char out[10];
    generate_subsequences(inp,out,0,0);
    return 0;
}