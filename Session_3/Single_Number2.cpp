int Solution::singleNumber(const vector<int> &A) {
    int a=0;

    for(int i=0;i<32;i++){
        int b=0;

        for(int x:A){
            if(x&(1<<i)) b++;
        }

        if(b%3) a|=(1<<i);
    }

    return a;
}
