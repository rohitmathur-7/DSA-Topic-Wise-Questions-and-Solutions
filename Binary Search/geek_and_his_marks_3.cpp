#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    int q;cin>>q;
	    int x;
	    while(q--){
	        cin>>x;
            int pos=upper_bound(arr,arr+n,x)-arr;
            int sum=0;
            for(int i=pos;i<n;i++) sum+=arr[i];
            cout<<sum<<endl;
	    }
	}
	return 0;
}