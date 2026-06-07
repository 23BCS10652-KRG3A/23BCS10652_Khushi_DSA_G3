#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long power(long long a,long long b){
    long long r=1;
    while(b){
        if(b&1) r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    int a=0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]) a++;
    }

    int b=n-a;

    vector<long long>f(n+1),inv(n+1);
    f[0]=1;

    for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;

    inv[n]=power(f[n],mod-2);

    for(int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;

    auto C=[&](int n,int r)->long long{
        if(r<0||r>n) return 0;
        return f[n]*inv[r]%mod*inv[n-r]%mod;
    };

    int t=(k+1)/2;
    long long ans=0;

    for(int i=t;i<=k;i++){
        ans=(ans+C(a,i)*C(b,k-i))%mod;
    }

    cout<<ans<<"\n";
    return 0;
}
