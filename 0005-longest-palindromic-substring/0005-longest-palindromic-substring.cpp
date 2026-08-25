class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string LPS = string(1,s[0]);
        for(int i=1;i<n;i++){
            int low = i;
            int high =i;
            while((low>=0  && high<n)&& s[low]==s[high]){
                low--;
                high++;
            }
            string palindrome = s.substr(low+1,high-low-1);
            if(palindrome.size()>LPS.size()) LPS = palindrome;

            low = i-1;
            high = i;
            while((low>=0 && high<n) && s[low]==s[high]){
                low--;
                high++;
            }
            palindrome = s.substr(low+1,high-low-1);
            if(palindrome.size()>LPS.size()) LPS = palindrome;

        }
        return LPS;
      
    }
};