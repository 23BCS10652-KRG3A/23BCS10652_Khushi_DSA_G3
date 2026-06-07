#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;

    vector<int>b(a);
    int c=0;

    for(int i=0;i<a;i++){
        cin>>b[i];
        c=max(c,b[i]);
    }

    vector<int>d(c+1);
    for(int x:b)d[x]++;

    vector<int>e(c+1,1),f(c+1),g(c+1);

    for(int i=2;i<=c;i++){
        if(!f[i]){
            for(int j=i;j<=c;j+=i){
                f[j]=1;
                e[j]*=-1;
                g[j]++;
            }
            long long h=1LL*i*i;
            if(h<=c){
                for(long long j=h;j<=c;j+=h) e[j]=0;
            }
        }
    }

    long long ans=0;

    for(int i=1;i<=c;i++){
        long long cnt=0;
        for(int j=i;j<=c;j+=i) cnt+=d[j];
        ans+=1LL*e[i]*cnt*(cnt-1)/2;
    }

    cout<<ans<<endl;
    return 0;
}
