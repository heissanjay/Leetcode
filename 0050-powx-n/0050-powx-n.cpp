class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }
       
        if (n < 0) {
            return binaryExp(1.0 / x, -n); 
        }
       
        double half_pow = binaryExp(x, n / 2);
        double result = (n % 2 == 0) ? half_pow * half_pow : half_pow * half_pow * x;
        return result;
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long)n);
    }
};
