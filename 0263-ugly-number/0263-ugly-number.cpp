class Solution {
public:
    bool isUgly(int n) {
        if(!n)
            return false;     
        while(n % 2 == 0)
            n /= 2;
        while(n % 5 == 0)
            n /= 5;
        while(n % 3 == 0)
            n /= 3;
        if(n == 1)
            return true;
        else
            return false;
        
        return true;
        
    }
};