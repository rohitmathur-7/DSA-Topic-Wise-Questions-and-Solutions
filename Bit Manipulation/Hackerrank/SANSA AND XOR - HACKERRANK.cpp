**QUES - HACKERRANK Sansa and XOR**
int sansaXor(vector<int> arr) {
    int res=0;
    int s=arr.size();
    for(int i=0;i<arr.size();i++){
          int a=(i+1)*(s-i);
          if(a%2!=0) res^=arr[i];
    }
    return res;
}
