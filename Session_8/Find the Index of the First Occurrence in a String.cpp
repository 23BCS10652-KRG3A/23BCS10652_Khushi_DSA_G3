class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        vector<int>lps(n,0);

        for(int i=1,len=0;i<n;){
            if(needle[i]==needle[len]){
                lps[i++]=++len;
            }else{
                if(len) len=lps[len-1];
                else lps[i++]=0;
            }
        }

        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==n) return i-j;
            }else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return -1;
    }
};
