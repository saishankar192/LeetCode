class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<int> decArray(sz);
        decArray[sz-1] = prices[sz-1];

        for(int i=sz-2; i>=0;i--){
            decArray[i] = max(prices[i], decArray[i+1]);
        }

        int maxAns = INT_MIN;
        for(int i=0;i<sz;i++){
            maxAns = max(maxAns, decArray[i]-prices[i]);
        }

        return maxAns<0 ? 0 : maxAns;
    }
};