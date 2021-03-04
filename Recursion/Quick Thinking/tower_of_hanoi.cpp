// QUES: Tower of Hanoi(Given n disks and 3 towers(A,B and C), move all the disk from A to C but while moving no larger
//       disks can come above a smaller disk.)

#include<bits/stdc++.h>
using namespace std;

void move(int n,char src,char helper,char dest){
    //base case
    if(n==0) return;
    //rec case
    move(n-1,src,dest,helper); //first we shift the n-1 disks from A to B, i.e from src to helper(So we are just saying here that n-1 disks are moved from A to B, but actually the particular disks are moved around one by one with the help of recursion.)
    cout<<"Shift disk "<<n<<" from "<<src<<" to "<<dest<<endl; //now we move nth disk from src to dest, i.e from A to C
    move(n-1,helper,src,dest); //Now we move the n-1 disks from helper to dest
}

int main(){
    int n; //number of disks
    cin>>n;
    move(n,'A','B','C');
}