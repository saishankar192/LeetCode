class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        unordered_map<int, int> um;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                um[nums1[i]+nums2[j]]++;
            }
        }

        for(int k=0;k<nums3.size();k++){
            for(int l=0;l<nums4.size();l++){
                cnt += um[-(nums3[k]+nums4[l])];
            }
        }
        return cnt;
    }
};