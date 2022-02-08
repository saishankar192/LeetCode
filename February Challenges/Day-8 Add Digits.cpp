class Solution {
public:
   int SumOfDigits(int n){
        int res=0;
        while(n>=1){
            res += (n%10);
            n /= 10;
        }
        return res;
    }
    int addDigits(int num) {
        while(num>9){
            num = SumOfDigits(num);
        }
        return num;
    }
};