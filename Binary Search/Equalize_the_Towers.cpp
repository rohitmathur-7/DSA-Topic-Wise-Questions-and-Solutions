/*
    Problem: https://practice.geeksforgeeks.org/problems/equalize-the-towers2804/1/?page=1&category[]=Binary%20Search&query=page1category[]Binary%20Search#
    
    Explanation:
    Its a slight variation of binary search, so we are not able to figure out directly how to use binary search.

    So how we should think is something like this -
    
    We will take low as 0 and high as the highest height in array + 1,
    and then we will calculate the mid ,
    now we will calculate the cost it will take to bring all the heights to mid,
    and also we will calculate the cost it will take to bring all the heights to mid-1, and also to mid+1.

    Now if the cost calculated from mid+1 is smaller than the cost from mid, then it means there exists atleast 1 height in range mid+1 to high which will give us a smaller answer than mid,so in this case we will make our low=mid+1,

    Now if the cost calculated from mid-1 is smaller than the cost from mid, then it means there exists atleast 1 height in range low to mid-1 which will give us a smaller answer than mid,so in this case we will make our high=mid-1,

    And finally if mid gives us a smaller answer than both mid+1 and mid-1,
    then that is our Answer!
    
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