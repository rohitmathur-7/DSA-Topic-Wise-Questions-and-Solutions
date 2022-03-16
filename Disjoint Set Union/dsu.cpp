#include<bits/stdc++.h>
using namespace std;
vector<int> parent(100000);
vector<int> rnk(100000);

void makeset(){
    //initially setting parent of each node to itself and rank of each node as 0
    for(int i=1;i<100000;i++){
        parent[i]=i;
        rnk[i]=0;
    }   
}

int findParent(int node){
    //if node is parent of itself then return it
    if(node==parent[node]) return node;

    /*
    else we want to find the parent of the node,
    suppose 7->6->4->1
    we want to find parent of node 7,then first it will go to 6 then 4 and then 1,
    this takes a lot of time,
    to reduce this time taken we do "Path Compression".
    Path Compression is basically once we find the parent of 7 as 1, then we will assign
    parent of 7 as 1.
    7->1
    */
    return parent[node]=findParent(parent[node]);
}

void Union(int x,int y){
    //if rank of x < rank of y, then we will add x to y
    if(rnk[x]<rnk[y]){
        parent[x]=y;
    }
    //if rank of y < rank of x, then we will add y to x
    else if(rnk[y]<rnk[x]){
        parent[y]=x;
    }
    /*else we can assign anoyone to anoyone, x to y or y to x,
     and if we are assigning y to x then increase rank of x*/
    else{
        parent[y]=x;
        rnk[x]++;
    }
}

int main(){
    makeset();
    int n;cin>>n;//number of nodes
    int m;cin>>m;//number of edges
    int x,y;
    while(m--){
        cin>>x>>y;
        Union(x,y);
    }

    //if we want to check if 2 nodes belong to same componen then-
    //do not use parent array here bcz it does not give ultimate/final parent
    int a,b;cin>>a>>b;
    if(findParent(a)!=findParent(b)){
        cout<<"Different components";
    }
    else{
        cout<<"Same components";
    }

}