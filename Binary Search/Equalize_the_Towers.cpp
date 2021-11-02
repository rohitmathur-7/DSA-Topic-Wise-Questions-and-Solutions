/*
    Explanation:
    Its a slight variation of binary search, so we are not able to figure out directly how to use binary search.

    So how we should think is something like this -

    



*/


    class Solution{

    public:

        long long int cal(int n, int h[], int cost[],int height){
	        long long int required_cost=0;
	        for(int i=0;i<n;i++){
	            required_cost+=(abs(h[i]-height)*cost[i]);
	        }        
	        return required_cost;
	    }
	
	    long long int Bsearch(int n, int h[], int cost[]) 
	    {    
		    // Your code goes here
		    long long int mx=INT_MIN;
		    for(long long int i=0;i<n;i++){
		        if(h[i]>mx) mx=h[i];
		    }
		    mx++;
		
	    	long long int high=mx,low=0,mid;
		    while(low<=high){
		        mid=(low+high)>>1;
		    
		        long long int before_mid=cal(n,h,cost,mid-1);
		        long long int after_mid=cal(n,h,cost,mid+1);
		        long long int at_mid=cal(n,h,cost,mid);
		    
		        if(before_mid<at_mid){
		            high=mid-1;
		        }
		        else if(after_mid<at_mid){
		            low=mid+1;
		        }
		        else{
		            return at_mid;
		        }
		    }
	    }
    };