//Ques:  Calculating factorial of a number

//if number is very large suppose 100, then its factorial won't fit in any data type in C++,
//so bcz of that we will have to use arrays and with help of them calc the factorial. 


#include<bits/stdc++.h>
using namespace std;

void multiply(int *a,int &n,int no){
    int carry=0;
    for(int i=0;i<n;i++){
        int product=(a[i]*no)+carry;
        a[i]=product%10;
        carry=product/10;
    }
    
    //in the end we can have a carry which havce more than 1 digit, so that's why we
    //will apply a loop until oure carry is not 0.
    while(carry){
        a[n]=carry%10;
        carry=carry/10;
        n++;
    }
}

void large_factorial(int number){
    int a[1000];//supposing that the max digits in a number is 1000
    memset(a,0,sizeof(a));//setting all the elements in array as 0.
    a[0]=1;//the first element is obviously going to be 0.
    int n=1;//n tells us that how many digits are currently in the array!
    for(int i=2;i<=number;i++){
        multiply(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
}

int main(){
    int number;
    cin>>number;
    large_factorial(number);
}