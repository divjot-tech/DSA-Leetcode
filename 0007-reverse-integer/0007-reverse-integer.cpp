class Solution {
public:
    int reverse(long long n) {
        long long rev = 0;
        while(n!=0){
            long long digit = n%10;
            rev = rev*10+digit;
            n = n/10;
        }
        if(rev>INT_MAX || rev<INT_MIN){
            return 0;
        }
        return rev;

        
    }
};