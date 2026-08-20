class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,char> mapS,mapT;
        for(int i=0;i<s.size();i++){
            char cs = s[i];
            char ct = t[i];
            if(mapS.count(cs) && mapS[cs]!=ct)return false;
            if(mapT.count(ct) && mapT[ct]!=cs)return false;

            mapS[cs] = ct;
            mapT[ct] = cs;

        }
        return true;
        
    }
};