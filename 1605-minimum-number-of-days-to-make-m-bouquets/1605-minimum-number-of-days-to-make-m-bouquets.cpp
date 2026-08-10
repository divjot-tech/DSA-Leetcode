class Solution {
public:
    int possible(vector<int> nums, int days, int k, int m) {
        int n = nums.size();
        int noOfB = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= days)
                cnt++;
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long val = k * 1LL * m * 1LL;
        if (val > n)
            return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int low = mini;
        int high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(nums, mid, k, m))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};