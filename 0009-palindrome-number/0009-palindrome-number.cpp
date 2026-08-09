class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0) return false;
        int original = n;
        long long rev = 0;
        while(n!=0){
            int digit = n%10;
            rev = (rev*10)+digit;
            n = n/10;
        }
        if(original==rev){
            return true;
        }
        else return false;
        
    }
};