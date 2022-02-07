class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> aux(26, 0);
        int i;
        for(i=0;i<s.size();i++){
            aux[s[i]-'a']--;
            aux[t[i]-'a']++;
        }
        aux[t[i]-'a']++;
        
        char diff;
        for(int i=0;i<26;i++){
            if(aux[i]){
                diff = 'a'+i;
                break;
            }
        }
        return diff;
    }
};