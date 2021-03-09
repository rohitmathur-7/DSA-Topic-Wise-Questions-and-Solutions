//QUES: given a keypad of a phone, the user gives some input.
        // Generate all the subsets possible of that input.
        // ex: input- 23
        // now 2 is mapped with "abc" and 3 is mapped with "def".
        // so possible subsets -
        // ad,ae,af,bd,be,bf,cd,ce,cf.
#include<iostream>
using namespace std;

char keypad[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generate_names(char *input,char *output,int i,int j){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    int digit=input[i] - '0';
    if(digit==1 || digit==0){
        //bcz the value that are mapped with 1 and 0 are null.
        //So we skip them.
        generate_names(input,output,i+1,j);
    }

    //iterate over all the values mapped with the particluar digit
    for(int k=0;keypad[digit][k]!='\0';k++){
        output[j]=keypad[digit][k];
        //for the remaining part
        generate_names(input,output,i+1,j+1);
    }
    return;
}


int main(){
    char input[100];
    cin>>input;
    char output[100];
    generate_names(input,output,0,0);
}










