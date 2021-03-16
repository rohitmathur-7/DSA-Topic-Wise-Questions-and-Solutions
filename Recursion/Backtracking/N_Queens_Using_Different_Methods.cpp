// //QUES: tell the number of ways in which you can arrange the N queens in the board.

// #include<bits/stdc++.h>
// using namespace std;
// bitset<100> col,d1,d2;
//col is for the column, d1 is for left diagonal and d2 for right digonal
// //advantage of using bitset is that, bitset of size 100 takes 100bits, but bool of size will take - 8*100 bits, bcz 1bool is of size 8bits.


// //METHOD 1 - naive approach
// //This fnc takes O(n) time
// bool isSafeToPlaceTheQueen(int board[][10],int i,int j,int n){

//     //check if any queen is present in the column of the current queen.
//     for(int row=0;row<i;row++){
//         //if any queen is present in the current column, return false
//         if(board[row][j]==1) return false;
//     }

//     int x=i,y=j;
//     //check along the left upper diagonal
//     while(x>=0 && y>=0){
//         if(board[x][y]==1) return false;
//         x--;y--;
//     }
//     x=i,y=j;
//     //check along the right upper diagonal
//     while(x>=0 && y<n){
//         if(board[x][y]==1) return false;
//         x--;y++;
//     }
    
//     //if no queen is present on the same column or on the left upper diagonal or right diagonal, then return true
//     return true;
// }

// void N_Queens(int i,int n,int &ans){
//     //base case
//     if(i==n){
//         ans++;return;
//     }
//     //rec case

//     //METHOD 1
//     //for(int j=0;j<n;j++){
//         // if(isSafeToPlaceTheQueen(board,i,j,n)){
//         //     //place the queen on position(i,j), assuming that this position is correct.
//         //     board[i][j]=1;
//         //     //check for the next queen
//         //     N_Queens(board,i+1,n,ans);
//         //     board[i][j]=0; 
//         // }      
//     // }

//     //METHOD 2 - bitset approach
//     //Now this will take only O(1) time to figure out if we can place the queen or not!
//     // for(int j=0;j<n;j++){
//     //     if(!col[j] && !d1[i+j] && !d2[i-j+n-1]){
//     //         col[j]=d1[i+j]=d2[i-j+n-1]=1;
//     //         N_Queens(i+1,n,ans);
//     //         col[j]=d1[i+j]=d2[i-j+n-1]=0;
//     //     }
//     // }
//     return;
// }

// int main(){
//     int n; //number of queens
//     cin>>n;
//     int ans=0;
//     int board[10][10]={0};
//     N_Queens(0,n,ans);
//     cout<<ans<<endl;
//     return 0;
// }


//METHOD 3 - Bitmasking
#include<bits/stdc++.h>
using namespace std;
int DONE,ans=0,n;


void N_Queens(int rowMask,int ld,int rd){
    //base case
    if(rowMask==DONE){  
        ans++;
        return;
    }

    //rec case
    //first find out the safe mask i.e possible positions where we can place the queen
    int safe = DONE & (~(rowMask | ld | rd));
    //in the other methods, we traversed over all the columns of a row,but here as we have the safe mask...so we already know that what are the safe positions to place the queen, so we will just traverse over them.
    while(safe){
        int p = safe & (-safe);
        safe = safe - p;
        N_Queens(rowMask|p,(ld|p)<<1,(rd|p)>>1);
    }
}  

int main(){
    cin>>n;
    DONE=((1<<n)-1);
    N_Queens(0,0,0);
    cout<<ans<<endl;
}

