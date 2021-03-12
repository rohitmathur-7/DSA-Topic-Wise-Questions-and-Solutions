// #become the best version of yourself.
// #you are the best.

#include<bits/stdc++.h>
using namespace std;

bool isSafeToPlaceTheQueen(int board[][10],int i,int j,int n){

    //check if any queen is present in the column of the current queen.
    for(int row=0;row<i;row++){
        //if any queen is present in the current column, return false
        if(board[row][j]==1) return false;
    }

    int x=i,y=j;
    //check along the left upper diagonal
    while(x>=0 && y>=0){
        if(board[x][y]==1) return false;
        x--;y--;
    }
    x=i,y=j;
    //check along the right upper diagonal
    while(x>=0 && y<n){
        if(board[x][y]==1) return false;
        x--;y++;
    }
    
    //if no queen is present on the same column or on the left upper diagonal or right diagonal, then return true
    return true;


}


bool N_Queens(int board[][10],int i,int n){
    //base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<"_ ";
            }
            cout<<endl;
        }
        // cout<<endl;
        //if we a want to just print one way of arranging N queens than return true, otherwise if we want to print all the possible ways in which the N queens can be arranged, then there is a hack that, if we return false here then we will be able to print all the ways.And this is bcz, even after finding a suitable way to arrange queens..the function will still return false, and due to that we will be able to print all the possible ways.
        
        return true;
    }

    //rec case
    for(int j=0;j<n;j++){
        if(isSafeToPlaceTheQueen(board,i,j,n)){
            //place the queen on position(i,j), assuming that this position is correct.
            board[i][j]=1;
            //check for the next queen
            bool next_queen=N_Queens(board,i+1,n);
            //if it was able to find a place to keep the queen, then return true
            if(next_queen==1){
                return true;
            }
            //else, it means that the position of the previous queen was wrong,So we backtrack.
            board[i][j]=0; 
        }
    }
    //we tried to for all positions in current row,but could not find a safe position, so we return false.
    return false;
}

int main(){
    int n; //number of queens
    cin>>n;
    int board[10][10]={0};
    N_Queens(board,0,n);
    return 0;
}




