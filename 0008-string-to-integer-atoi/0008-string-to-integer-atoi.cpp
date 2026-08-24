class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        int sign = 1;
        if(s[i]=='+'|| s[i]=='-'){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }
        long long result = 0;
        while(s[i]>='0' && s[i]<='9'){
            result = result*10+(s[i]-'0');

            if(result*sign<INT_MIN) return INT_MIN;
            if(result*sign>INT_MAX) return INT_MAX;
            i++;
        }
        return (result*sign);
        
    }
};