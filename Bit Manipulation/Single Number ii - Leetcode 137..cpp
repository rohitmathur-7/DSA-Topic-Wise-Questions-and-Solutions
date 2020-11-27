//**//**QUES - SINGLE NUMBER 2  LEETCODE 137**

//**METHOD 1 (HASH MAP + LINEAR TRAVERSAL)    T.C - O(nlog(n))    S.C - O(n)
//class Solution {
//public:
//    int singleNumber(vector<int>& nums){
//    	map<int,int> m;
//        for(int i=0;i<nums.size();i++){
//        	m[nums[i]]++;
//		}
//        int x;
//		for(auto it:m){
//			if(it.second==1) x=it.first;
//		}
//        return x;
//    }
//};

//**METHOD 2 (SORTING + LINEAR TRAVERSAL)    T.C - O(nlog(n) + n)
//class Solution {
//public:
//    int singleNumber(vector<int>& nums){
//        int s=nums.size();
//        if(s<3) return nums[0];
//        sort(nums.begin(),nums.end());
//        if(nums[0]!=nums[1]) return nums[0];
//		int i=1;
//		while(i<s){
//			if(nums[i]!=nums[i-1]) return nums[i-1];
//			i+=3;
//		}
//        return nums[s-1];
//    }
//};

//**METHOD 3 (COUNTING SET BITS)				T.C - O(32*n)
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int res=0;
//        int shift=0;
//        for(int i=0;i<32;i++){
//            int cnt=0;
//            for(auto ele : nums){
//                if(ele & (1<<shift)) cnt++;
//            }
//            if((cnt%3) !=0) res+=(1<<shift);
//            shift++;
//        }    
//        return res;
//    }
//};


//**METHOD 4 (ONES AND TWOS)                	T.C - O(n)
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ones=0;bool ones=true;
//        int twos=0;bool twos=false;
//        for(int i=0;i<nums.size();i++){
//        	if(ones){
//        		ones=((ones^nums[i]) & (~twos));
//        		ones=false;
//        		twos=true;
//			}
//        	if(twos){
//        		twos=((twos^nums[i]) & (~ones));
//        		twos=false;
//        		ones=true;
//			}
//		}
//		return ones;
//    }
//};
