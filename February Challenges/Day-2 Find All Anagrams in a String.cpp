class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};
        
        string phash(26, '0'), shash(26, '0');
        vector<int> ans;
        int n = p.size();
        int m = s.size();
        
        for(int i=0;i<p.size();i++){
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        
        if(shash == phash)
            ans.push_back(0);
        
        
        for(int i=n;i<m;i++){
            shash[s[i-n]-'a']--;
            shash[s[i]-'a']++;
            if(shash == phash)
                ans.push_back(i-n+1);
         }
        return ans;
    }
};