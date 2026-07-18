class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        int lastSm = INT_MIN;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSm){
                cnt=cnt+1;
                lastSm = nums[i];
            }
            else if(nums[i]!=lastSm){
                cnt = 1;
                lastSm = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
        
    }
};