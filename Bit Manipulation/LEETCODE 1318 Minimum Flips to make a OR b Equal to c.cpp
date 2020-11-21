
//**QUES - Minimum Flips to Make a OR b Equal to c  (LEETCODE 1318)**

//**METHOD 1(MY SOLUTION)[USING RIGHT SHIFT]**
//class Solution {
//public:
//    int minFlips(int a, int b, int c){
//      int cnt=0;
//		int *m;
//		m=(a>b)?(a>c?&a:&c):(b>c?&b:&c);
//        while(*m){		
//			int q=a|b;																				
//            if((c & 1) != (q & 1)){
//                int co=c&1;
//                int ao=a&1;
//                int bo=b&1;
//                if(co==1) cnt++;
//                else{
//                    if((ao==1 && bo==0) || (ao==0 && bo==1)) cnt++;
//                    else cnt+=2;
//                }
//            }
//            c>>=1;a>>=1;b>>=1;
//        }
//        return cnt;
//    }
//};
//
//int main(){
//int t;
//	cin>>t;
//	Solution s;
//	while(t--){
//		int a,b,c;
//		cin>>a>>b>>c;
//		cout<<s.minFlips(a,b,c)<<endl;
//	}
//}

//**METHOD 2[USING LEFT SHIFT]**
//class Solution {
//public:
//    int minFlips(int a, int b, int c){
//        int cnt=0;
//		for(int i=0;i<32;i++){
//			bool x=false,y=false,z=false;
//			if(a & (1<<i)) x=true;
//			if(b & (1<<i)) y=true;
//			if(c & (1<<i)) z=true;
//			if(z==false){
//				if(x==true && y==true) cnt+=2;
//				else{
//                    if(x==true || y==true) cnt++;
//                }
//			}
//			else{
//                if(x==false && y==false) cnt++;
//            }
//		}
//        return cnt;
//    }
//};
//
//int main(){
//int t;
//	cin>>t;
//	Solution s;
//	while(t--){
//		int a,b,c;
//		cin>>a>>b>>c;
//		cout<<s.minFlips(a,b,c)<<endl;
//	}
//}

