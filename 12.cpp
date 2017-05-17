/*****************************************************
 * 
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * 
 *****************************************************/

#include <string>
#include <iostream>

using namespace std;

/*****************************************************/

class Solution {
public:
    string intToRoman(int num) {
        // I :    1
        // V :    5
        // X :   10
        // L :   50
        // C :  100
        // D :  500
        // M : 1000
        string res;
        string table[4][10] {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM", "",   "",  "",   "",    "",     ""  }
        };
        int thousand = num/1000;
        int hundred = num%1000/100;
        int ten = num%100/10;
        int one = num%10;

        res += table[3][thousand];
        res += table[2][hundred];
        res += table[1][ten];
        res += table[0][one];

        return res;
    }
};

/*****************************************************/

int main() {
    Solution s;
    cout << s.intToRoman(12) <<endl;
}

