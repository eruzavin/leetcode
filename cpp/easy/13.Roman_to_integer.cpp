#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* Popular approach with map
     * Cons: kinda elegant
     * Pros: it is slower and more memory consuming than solution with 'case'
     *
     * Note: I changed the iteration algorithm to avoid using out of bounds indecies
    */
    int romanToInt_v1(string s) {
        unordered_map <char,int> numsMap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = numsMap[s.back()];

        for(size_t i = 1; i < s.size(); ++i){
            int prevNum = numsMap[s[i - 1]];
            int currNum = numsMap[s[i]];

            if (prevNum < currNum) {
                result -= prevNum;
            }
            else {
                result += prevNum;
            }
        }

        return result;
    }

    // Simple and fast solution with `case` switch
    int romanToInt_v2(string s) {
        int result = 0;

        for (size_t i = 0; i != s.size(); ++i) {

            switch (s[i]) {

            case 'I':
                if (s[i + 1] == 'V') {
                    result += 4;
                    ++i;
                    break;
                }
                else if (s[i + 1] == 'X') {
                    result += 9;
                    ++i;
                    break;
                }
                result += 1;
                break;

            case 'V':
                result += 5;
                break;

            case 'X':
                if (s[i + 1] == 'L') {
                    result += 40;
                    ++i;
                    break;
                }
                else if (s[i + 1] == 'C') {
                    result += 90;
                    ++i;
                    break;
                }
                result += 10;
                break;

            case 'L':
                result += 50;
                break;

            case 'C':
                if (s[i + 1] == 'D') {
                    result += 400;
                    ++i;
                    break;
                }
                else if (s[i + 1] == 'M') {
                    result += 900;
                    ++i;
                    break;
                }
                result += 100;
                break;

            case 'D':
                result += 500;
                break;

            case 'M':
                result += 1000;
                break;
            }
        }

        return result;
    }
};

/* main.cpp
#include <iostream>
#include "./easy/13.Roman_to_integer.cpp"

int main()
{
    Solution s;

    std::cout << s.romanToInt_v1("MCMXCIV") << std::endl;
}
*/

/* TASK
https://leetcode.com/problems/roman-to-integer/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */
