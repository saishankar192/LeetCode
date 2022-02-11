class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int sum = 0, cnt=0;
        um[0]++;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(um.count(sum-k))
                cnt += um[sum-k];
            else
                um[sum]++;
        }
        return cnt;
    }
};