//Divide two integers without using multiplication, division and mod operator.

#include <iostream>
#include <climits>
using namespace std;

/****************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
        }

        if (divisor == 0) {
            return INT_MAX;
        }

        bool negDividend = dividend < 0? true:false;
        bool negDivisor = divisor < 0? true:false;

        long long pos_dividend = dividend;
        long long pos_divisor = divisor;
        if (negDividend) pos_dividend = -pos_dividend;
        if (negDivisor) pos_divisor = -pos_divisor;


        if (pos_dividend < pos_divisor) {
            return 0;
        }

        long long res = 0;
        int count = 0;
        auto tmp = pos_divisor;
        while (tmp <= pos_dividend) {
            tmp = tmp << 1;
            count += 1;
        }

        while (count >= 0) {
            if (tmp <= pos_dividend) {
                res += 1 << count;
                pos_dividend -= tmp;
            } else {
                count --;
                tmp = tmp >> 1;
            }
        }

        cout << res << endl;
        return negDividend == negDivisor ? res: -res;
    }
};

/****************************************************************/

int main() {
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
}
