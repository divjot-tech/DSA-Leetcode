class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        long ans = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini = INT_MAX;
                int maxi = 0;
                for(int f:freq){
                    if(f>0){
                        mini = min(mini,f);
                        maxi = max(maxi,f);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};