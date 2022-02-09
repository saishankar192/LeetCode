class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(auto ele: nums)
            um[ele]++;
        
        int cnt = 0;
        for(auto pr: um){
            if(mp.count(pr.first-k))
                cnt++;
        }

        return cnt;
    }
};