//QUES: Given a N*N suduko, solve it and print the suduko.

#include<bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int number,int n){
    //checking if the same number is present already in the current column or row.
    for(int x=0;x<n;x++){
        //if present return false
        if(mat[x][j]==number || mat[i][x]==number) return false;
    }

    //chrck for the subgrid
    //in a grid of size nXn, there are n subgrids of size sqrt(n) each.
    //now to know if the number exists in the subrid, then first we find out in which subgrid we are..
    //and we do that by - ( (current row)/sqrt(n),(current column)/sqrt(n) ).
    //and to find the starting point - 
    //( ((current row)/sqrt(n))*sqrt(n),((current column)/sqrt(n))*sqrt(n) )

    int rn=sqrt(n); 
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;

    for(int x=sx;x<(sx+rn);x++){
        for(int y=sy;y<(sy+rn);y++){
            if(mat[x][y]==number) return false;
        }
    }
    //else return true, which means that we can place the current number.
    return true;
}

bool solveSuduko(int mat[][9],int i,int j,int n){
    //base case
    if(i==n){
        //print the suduko
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n) return solveSuduko(mat,i+1,0,n); //if we reach the end of a row

    if(mat[i][j]!=0) return solveSuduko(mat,i,j+1,n); //if there is already a number present

    //rec case

    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,number,n)){
            //assuming that this is correct
            mat[i][j]=number;
            bool couldSolve=solveSuduko(mat,i,j+1,n);
            if(couldSolve==true) return true; //if we could solve the suduko further by putting number at this position, then return true.
        }
    }
    //if none of the number could solve the suduko further, then we backtrack and make the current cell as 0.
    mat[i][j]=0;
    return false;
}


int main(){
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    solveSuduko(mat,0,0,9);
    return 0;
}