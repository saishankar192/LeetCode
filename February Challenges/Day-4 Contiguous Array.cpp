class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> um;
        int currSum = 0, maxLen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1)
                currSum++;
            else
                currSum--;
            
            if(currSum==0){
                maxLen = max(maxLen, i+1);
            }
            else if(um.find(currSum) != um.end()){
                maxLen = max(maxLen, (i-um[currSum]));
            }
            else{
                um[currSum] = i;
            }
        }
        return maxLen;
    }
};