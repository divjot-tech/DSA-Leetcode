class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;

        for(char i:s){
            mpp1[i]++;
        }
        for(char i:t){
            mpp2[i]++;
        }
        if(mpp1==mpp2) return true;
        else return false;

        
    }
};