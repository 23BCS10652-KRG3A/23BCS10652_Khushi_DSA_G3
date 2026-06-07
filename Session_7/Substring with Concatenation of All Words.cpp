class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=s.size();
        int m=words.size();
        int len=words[0].size();

        unordered_map<string,int> mp;
        for(auto &w:words) mp[w]++;

        for(int i=0;i<len;i++){
            int left=i,count=0;
            unordered_map<string,int> curr;

            for(int right=i;right+len<=n;right+=len){
                string word=s.substr(right,len);

                if(mp.count(word)){
                    curr[word]++;
                    count++;

                    while(curr[word]>mp[word]){
                        string rem=s.substr(left,len);
                        curr[rem]--;
                        left+=len;
                        count--;
                    }

                    if(count==m){
                        ans.push_back(left);
                        string rem=s.substr(left,len);
                        curr[rem]--;
                        left+=len;
                        count--;
                    }
                }
                else{
                    curr.clear();
                    count=0;
                    left=right+len;
                }
            }
        }
        return ans;
    }
};
