class Solution {
public:
    string longestDupSubstring(string s) {
        int n=s.size();
        long long mod=1000000007;
        long long base=31;

        auto check=[&](int len)->int{
            if(len==0) return 0;

            long long hash=0,power=1;

            for(int i=0;i<len;i++){
                hash=(hash*base+(s[i]-'a'+1))%mod;
                if(i<len-1) power=(power*base)%mod;
            }

            unordered_set<long long> st;
            st.insert(hash);

            for(int i=len;i<n;i++){
                hash=(hash-(s[i-len]-'a'+1)*power%mod+mod)%mod;
                hash=(hash*base+(s[i]-'a'+1))%mod;

                if(st.count(hash))
                    return i-len+1;

                st.insert(hash);
            }

            return -1;
        };

        int l=1,r=n-1;
        int start=-1,len=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            int pos=check(mid);

            if(pos!=-1){
                start=pos;
                len=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        return start==-1?"":s.substr(start,len);
    }
};
