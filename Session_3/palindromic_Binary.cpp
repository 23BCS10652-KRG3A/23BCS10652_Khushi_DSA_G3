int solve(int A) {
    int a=1,b=1;

    while(a<A){
        b++;
        a+=(1<<((b-1)/2));
    }

    a-=(1<<((b-1)/2));

    int c=A-a-1;

    int d=(1<<(b-1));

    d|=(c<<(b/2));

    int e=d>>((b+1)/2);

    while(e){
        d=(d<<1)|(e&1);
        e>>=1;
    }

    return d;
}
