class Solution {
public:
    string getSmallestString(int n, int k) {
        string str;
        for(int i=0;i<n;i++)
            str += 'a';
        
        while(n--){
            if(k-n >= 26){
                str[n] = 'z';
                k -= 26;
            }
            else{
                int temp = (k-n) + (int)('a') - 1;
                str[n] = (char)temp;
                k -= (k-n);
            }
        }
        
        return str;
    }
};