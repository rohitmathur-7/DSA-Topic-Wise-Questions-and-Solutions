**QUES - HACKERRANK - AND PRODUCT**
long andProduct(long a, long b) {
    long res=0;
    long d=b-a;
    long f=1;
    for(long i=0;i<32;i++){
        if(d > (f<<i)) continue;
        else{
            if((a & (f<<i)) && (b & (f<<i))) res+=(f<<i);
        }
    }
    return res;
}
