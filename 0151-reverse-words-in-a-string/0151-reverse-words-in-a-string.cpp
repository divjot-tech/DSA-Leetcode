class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ' ) i++;
            if(i>=n) break;

            string word = "";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            words.push_back(word);
        }
        reverse(words.begin(),words.end());

        string result = "";
        for(int j=0;j<words.size();j++){
            result+=words[j];
            if(j!=words.size()-1) result+=" ";
        }
        return result;

        
    }
};