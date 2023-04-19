/*
Given a string s, return the longest
palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
//#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result, substr;

        // Создаем карту символов
        map<char, set<int>> charsMap;
        for (size_t i = 0; i != s.size() - 1; ++i) {
            charsMap[s[i]].insert(i);
        }

        for (size_t i = 0; i != s.size() - 1; ++i) {
            charsMap[s[i]].;
        }

        return result;
    }

//    string longestPalindrome(string s) {
//        string result, substr;

//        int i = 0, j = s.size() - 1;
//        while (true) {
//            if (s[i] == s[j]) {
//                substr = s.substr(i, j - i + 1);
//                ++i;
//                --j;
//            }
//            else if (i == j) { // Прошлись и обнаружили, что строка - палиндром
//                result = max(result, substr);
//                ++i;
//            }
//            else { //
//                --j;
//            }

//        }

//        return result;
//    }

//    string longestPalindrome(string s) {
//        string result;

//        for (size_t i = 0, j = s.size() - 1; i != s.size(); ++i) {

//            while (s[i] != s[j]) {
//                --j;
//            }

//            if (i == j) {
//                j = s.size() - 1;
//                continue;
//            }

//            string substr = s.substr(i, j - i + 1);



//            result = max(result, substr);
//        }

//        return result;
//    }
};
