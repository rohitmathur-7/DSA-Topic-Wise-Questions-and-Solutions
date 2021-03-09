//QUES: given a string as input, ex: 1234
// here 1 is mapped with A, 2 with B ....26 with Z.
// we want to generate as many string as possible!

// ex: string = 123,
//     output: ABC, LC, AW
    //    first we take 1,2 and 3 which gives "ABC", 
    //    then we take 12 as L and 3 as C which gives "LC",
    //    then we take 1 as A and 23 as W which gives us "AW".


#include<bits/stdc++.h>
using namespace std;

void generate_strings(char *input,char *output,int i,int j){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    
    //take single digit
    int digit=input[i]-'0';
    char ch=digit+'A'-1;
    output[j]=ch;
    generate_strings(input,output,i+1,j+1);

    //take 2 digits
    if(input[i+1]!='\0'){
        int second_digit=input[i+1]-'0';
        int no=digit*10 + second_digit;
        if(no<=26){
            ch=no+'A'-1;
            output[j]=ch;
            generate_strings(input,output,i+2,j+1);
        }
    }
    return;
}

int main(){
    char input[100];
    cin>>input;
    char output[100];
    generate_strings(input,output,0,0);
    return 0;
}