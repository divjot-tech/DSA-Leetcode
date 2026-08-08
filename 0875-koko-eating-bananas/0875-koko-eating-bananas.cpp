class Solution {
public:
int findMax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}
long long totalHours(vector<int> &v,int hours){
    long long totalH = 0;
    int n = v.size();
    for(int i=0;i<n;i++){
        totalH+=ceil((double)v[i]/(double)hours);
    }
    return totalH;
}
    int minEatingSpeed(vector<int> &v, int h) {
        int low = 1;
        int high = findMax(v);
        while(low<=high){
            int mid = (low+high)/2;
            long long midH = totalHours(v,mid);

            if(midH<=h) high = mid-1;
            else low = mid+1;
        }
        return low;
        
    }
};