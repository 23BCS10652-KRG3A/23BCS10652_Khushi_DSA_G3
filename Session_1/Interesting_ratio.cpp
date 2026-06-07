#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int a=1000000;
    vector<long long>b(a+1);
    vector<int>c(a+1);

    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j+=i){
            b[j]+=i;
            c[j]++;
        }
    }

    int d;
    cin>>d;
    while(d--){
        int e;
        cin>>e;
        cout<<b[e]-c[e]<<"\n";
    }
    return 0;
}
