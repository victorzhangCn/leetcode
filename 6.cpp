/************************************************
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 ***************************************/

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/***************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        string res(s);
        const int num_in_group = numRows==1 ? 1 : numRows*2-2;
        int num_of_groups = s.size() / num_in_group + 1;
        int index = 0;
        for (int row =0; row<numRows; ++row) {
            for (int i=0; i<num_of_groups; ++i) {
                string::size_type index1 = num_in_group*i + row;
                string::size_type index2 = num_in_group*i + numRows + (numRows - row - 2);
                if (index1 < s.size()) {
                    res[index++] = s[index1];
                }
                if (index2 < s.size() && row != 0 && row != numRows-1) {
                    res[index++] = s[index2];
                }
            }
        }
        return res;
    }
};

/***************************************/

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 7) <<endl;
    cout << s.convert("PAYPALISHIRING", 1) <<endl;
}
