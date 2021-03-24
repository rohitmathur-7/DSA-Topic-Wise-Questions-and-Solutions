/*
A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.


If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1
Sample Output
1
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int board[10][10];
int n,max_visited=0,sum=0;

void solve(int i,int j,int cnt){
    if(i<0 || j<0 || i>=10 || j>=10 || board[i][j]==0) return;

    board[i][j]=0; //unsets the current cell
    max_visited=max(max_visited,cnt+1); //max_visited stores the maximum of value of visited cells
    //try all 8 possible moves for knight
    solve(i-1,j-2,cnt+1);
    solve(i-2,j-1,cnt+1);
    solve(i+1,j-2,cnt+1);
    solve(i+2,j-1,cnt+1);
    solve(i-1,j+2,cnt+1);
    solve(i-2,j+1,cnt+1);
    solve(i+1,j+2,cnt+1);
    solve(i+2,j+1,cnt+1);
    board[i][j]=1;//again set the current cell(Backtracking)
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]==1) sum++;  //sum stores total number of valid cells on board
        }
    }

    solve(0,0,0);
    cout<<sum-max_visited<<endl;
}