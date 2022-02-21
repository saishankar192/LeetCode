class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1, ele=0;
        for(int i=1;i<nums.size();i++){
            if(nums[ele]==nums[i])
                cnt++;
            else
                cnt--;

            if(cnt<=0){
                cnt=1;
                ele = i;
            }
        }
        return nums[ele];
    }
};