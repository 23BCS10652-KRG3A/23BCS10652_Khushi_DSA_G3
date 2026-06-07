#include<bits/stdc++.h>
using namespace std;

int main(){

    int a;
    cin>>a;

    while(a--){
        int b;
        cin>>b;

        vector<int>c(b+1);

        for(int i=1;i<=b;i++) c[i]=i;

        for(int i=2;i<b;i+=2)
            swap(c[i],c[i+1]);

        swap(c[1],c[b]);

        for(int i=1;i<=b;i++)
            cout<<c[i]<<endl;
    }
}
