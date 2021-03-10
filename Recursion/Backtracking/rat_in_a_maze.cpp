//QUES: A rat wants to go from position(0,0) to the position(m-1,n-1) in a maze(M X N).
//      Help him find all the possible ways from which he can reach from the source to the desination!

#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n){
    //base case
    if(i==m && j==n){
        soln[i][j]=1;
        //print the path
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //if rat is in maze or not
    if(i>m || j>n) return false;
    //if the current cell is blocked, return false
    if(maze[i][j]=='X') return false;

    //assuming solution exists through current cell
    soln[i][j]=1;

    //rec case
    bool right = ratInMaze(maze,soln,i,j+1,m,n);
    bool down = ratInMaze(maze,soln,i+1,j,m,n);

    //backtracking
    soln[i][j]=0; // when we are returning, then we will mark the current cell as 0.

    //if either right or down is true
    if(right || down) return true;
    //else we just return false, bcz neither from right nor from down do we have a way to proceed ahead
    return false;
}


int main(){ 
    int m=4,n=4;
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10]={0};
    bool ans=ratInMaze(maze,soln,0,0,m-1,n-1);

    if(!ans) cout<<"Path not found!"<<endl;
    return 0;
}