/************************************************
 * 
 * Given a roman numeral, convert it to an integer.  
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 * 
 ***********************************************/

#include <iostream>
#include <string>

using namespace std;

/**********************************************/

class Solution {
public:
    int romanToInt(string s) {
        // I :    1
        // V :    5
        // X :   10
        // L :   50
        // C :  100
        // D :  500
        // M : 1000
        int index = 0;
        int length = 0;
        int thousand = romanToInt(s.substr(index), 'M', 'A', 'B', length); 
        index += length;
        int hundred = romanToInt(s.substr(index), 'C', 'D', 'M', length);
        index += length;
        int ten = romanToInt(s.substr(index), 'X', 'L', 'C', length);
        index += length;
        int one = romanToInt(s.substr(index), 'I', 'V', 'X', length);

        return 1000*thousand + 100*hundred + 10*ten + one;
    }

    int romanToInt(string s, char one, char five, char ten, int& length) {
        if (s.size() == 0){
            length = 0;
            return 0;
        }
        
        if (s[0] == one) {
            char second = nextChar(s, 0);
            if (second) {
                if (second == one) {
                    char third = nextChar(s, 1);
                    if (third && third == one) {
                        length = 3;
                        return 3;
                    } else {
                        length = 2;
                        return 2;
                    }
                } else if (second == five) {
                    length = 2;
                    return 4;
                } else if (second == ten) {
                    length = 2;
                    return 9;
                } else {
                    length = 1;
                    return 1;
                }
            } else {
                length = 1;
                return 1;
            }
        } else if (s[0] == five) {
            char second = nextChar(s, 0);
            if (second) {
                if (second == one) {
                    char third = nextChar(s, 1);
                    char fourth = nextChar(s, 2);
                    if (third != one) {
                        length = 2;
                        return 6;
                    } else if (fourth != one) {
                        length = 3;
                        return 7;
                    } else {
                        length = 4;
                        return 8;
                    }
                } else {
                length = 1;
                return 5;
                }
            } else {
                length = 1;
                return 5;
            }
        } else {
            length = 0;
            return 0;
        }
    }

    char nextChar(string s, string::size_type index) {
        if (s.size() <= index + 1) {
            return 0;
        } else {
            return s[index + 1];
        }
    }

};

/**********************************************/

int main() {
    Solution s;
    cout << s.romanToInt("XII") << endl;
}

