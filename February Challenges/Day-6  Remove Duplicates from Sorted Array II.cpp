class Solution {
public:
    int getJ(int i, vector<int>& nums){
        int j = i+1;
        while(j<nums.size() && nums[j]==100000){
            j++;
        }

        return j==nums.size() ? -1 : j;
    }

    int removeDuplicates(vector<int>& nums) {
        int cnd=nums[0], c=1, tcnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnd==nums[i] && c){
                tcnt++;
                c--;
            }
            else if(cnd!=nums[i]){
                tcnt++;
                cnd = nums[i];
                c=1;
            }
            else{
                nums[i]=100000;
            }
        }

        for(int i=0;i<tcnt;i++){
            if(nums[i]==100000){
                int j = getJ(i, nums);
                if(j==-1)
                    return tcnt;
                
                while(j<nums.size() && nums[j]!=100000){
                    swap(nums[i], nums[j]);
                    i++;
                    j++;

                    if(j<nums.size() && nums[j]==100000){
                        j = getJ(j, nums);
                        if(j == -1)
                            return tcnt;
                    }
                }
            }
        }
        return tcnt;
    }
};