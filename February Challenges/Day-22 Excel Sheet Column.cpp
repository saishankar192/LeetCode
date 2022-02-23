class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, p = 0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans += (pow(26,p) * ((columnTitle[i]-'A')+1));
            p++;
        }
        return ans;
    }
};