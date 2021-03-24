/* QUES: 
You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.

Input Format
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints
1 ≤ N,M ≤ 1000 There is at least one dry cell and one cell filled with water in the matrix.

Output Format
Print a single integer representing the largest possible size of the pond.

Sample Input
3 3
0 1 1
0 0 1
0 1 0

Sample Output
5

Explanation
Watering the cell at coordinates [2,2] unites the 2 ponds with sizes 1 and 3, resulting a pond of size 5, including the newly watered cell.
*/

#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> o,z;
map<int,int> mp;
int ans=0,strt;
set<int> st;


int newArea(){
	int cn=1;
	for(auto j:st){
		cn+=mp[j];
	}
	return cn;
}

bool safe(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m || visited[x][y]) return false;
	return true;
}

int dfs(int x,int y){
	//base case
	if(!safe(x,y)) return 0;
	//rec case
	int cn=1;
	arr[x][y]=strt;
	visited[x][y]=1;
	if(x+1<n && arr[x+1][y]==1){
		cn+=dfs(x+1,y);
		visited[x+1][y]=1;
	}
	if(x-1>=0 && arr[x-1][y]==1){
		cn+=dfs(x+-1,y);
		visited[x-1][y]=1;
	}
	if(y+1<n && arr[x][y+1]==1){
		cn+=dfs(x,y+1);
		visited[x][y+1]=1;
	}
	if(y-1>=0 && arr[x][y-1]==1){
		cn+=dfs(x,y-1);
		visited[x][y-1]=1;
	}

	return cn;
}


void go(){
	strt=5;
	for(auto xx:o){
		if(visited[xx.first][xx.second]) continue;
		mp[strt] = dfs(xx.first,xx.second);
		strt++;
		ans=max(ans,mp[strt]);
	}
	
	for(auto i:z){
		int r = i.first;
		int c = i.second;
        
		st.clear();

		if( (r - 1) >= 0 and arr[r-1][c] > 4 ) st.insert( arr[r-1][c] );
		if( (c - 1) >= 0 and arr[r][c-1] > 4 ) st.insert( arr[r][c-1] );
		if( (r + 1) < n and arr[r+1][c] > 4 ) st.insert( arr[r+1][c] );
		if( (c + 1) < m and arr[r][c+1] > 4 ) st.insert( arr[r][c+1] );

		int add = newArea();

		ans  = max( ans , add );
	}
	cout<<ans<<endl;
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1) o.push_back(make_pair(i,j));
			else z.push_back(make_pair(i,j));
		}
	}
	memset(visited,false,sizeof(visited));
	go();
	return 0;
}


