// QUES: Given a wall of size 4*n, and tiles of size (1,4) and (4,1).In how many ways you can build the wall?


#include<bits/stdc++.h>
using namespace std;

int place_tiles(int n){
    //base case
    if(n<=3) return 1;  //when n<=3, we can build the wall in only 1 way using the bricks of size (4,1).
                        // and at n=4 no. of ways is 2.

    //rec case
    //now suppose the number of ways to build a wall of size 4*n is f(n).
    //now to put the first brick of the wall there can be 2 ways-

    //1)We put the brick of size (4,1) first.By doing so, we are left with a wall of size n-1.
    //The remaining wall of size n-1, can be build in f(n-1) ways.

    //2)We put the brick of size (1,4) first.By doing so, we are left with a wall of size n-4.
    //The remaining wall of size n-4, can be build in f(n-4) ways.

    // So, f(n) = f(n-1) + f(n-4);
    return place_tiles(n-1)+place_tiles(n-4);

}

int main(){
    int n;
    cin>>n;
    cout<<place_tiles(n)<<endl;
}