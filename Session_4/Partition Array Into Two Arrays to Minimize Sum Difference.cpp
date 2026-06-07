class Solution {
public:
    int minimumDifference(vector<int>& a) {
        int n=a.size()/2;

        vector<vector<long long>> b(n+1),c(n+1);

        for(int m=0;m<(1<<n);m++){
            long long s1=0,s2=0;
            int cnt=0;

            for(int i=0;i<n;i++){
                if(m&(1<<i)){
                    cnt++;
                    s1+=a[i];
                    s2+=a[i+n];
                }
            }

            b[cnt].push_back(s1);
            c[cnt].push_back(s2);
        }

        long long s=accumulate(a.begin(),a.end(),0LL);

        for(int i=0;i<=n;i++)
            sort(c[i].begin(),c[i].end());

        long long ans=LLONG_MAX;

        for(int i=0;i<=n;i++){
            for(long long x:b[i]){
                int j=n-i;

                long long t=s/2-x;

                auto it=lower_bound(c[j].begin(),c[j].end(),t);

                if(it!=c[j].end()){
                    long long cur=x+*it;
                    ans=min(ans,llabs(s-2*cur));
                }

                if(it!=c[j].begin()){
                    --it;
                    long long cur=x+*it;
                    ans=min(ans,llabs(s-2*cur));
                }
            }
        }

        return (int)ans;
    }
};
