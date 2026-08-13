class Solution {
public:
int findSum(vector<int> &nums,int largest){
    int n = nums.size();
    int painters = 1;
    long long currSum = 0;
    for(int i=0;i<n;i++){
        if(currSum+nums[i]<=largest){
            currSum+=nums[i];
        }
        else{
            painters++;
            currSum=nums[i];
        }
    }
    return painters;
}    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            if(findSum(nums,mid)>k){
                low=mid+1;
            }
            else high = mid-1;
        }
        return low;
        
    }
};