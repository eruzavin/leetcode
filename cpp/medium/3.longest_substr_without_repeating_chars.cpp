/*
Given a string s, find the length of the longest
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    Индексы dict соответствуют ASCII-кодам, от 0 до 255. Значения dict - это индекс символа в строке s (по умолчанию -1).
    start - начало текущей подстроки, которую мы рассматриваем. Это индекс в строке s.

    Перебирая символы - элементы s, мы записываем в dict индекс i - позицию текущего символа в s.

    Если значение в dict больше, чем start, значит символ уже присутствует в подстроке, и нам надо начать рассматривать новую подстроку.
    Для этого start'у присваивается значение из dict (индекс предыдущего расположения символа в s).

    Каждый раз мы сравниваем длину подстроки (i - start) и maxLen, и, если она больше, чем maxlen, то перезаписываем maxLen.
    */
    int lengthOfLongestSubstring(const string& s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;

        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;

            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }


    // Approach with sliding window, works faster than lengthOfLongestSubstring_v3(...)
    int lengthOfLongestSubstring_v2(string s) {
        if (s.size() < 2) {
            return static_cast<int>(s.size());
        }

        int result = 1, i = 1;

        struct sWindow {
            string val;
            int pos = 0;
            int length = 1;
        };

        sWindow w;
        while(i < s.size()) {
            w.val = s.substr(w.pos, w.length);

            while (w.val.find(s[i]) != string::npos) {
                ++w.pos; --w.length;
                w.val = s.substr(w.pos, w.length);
            }

            ++w.length; ++i;
            result = max(result, w.length);
        }

        return result;
    }


    // Brute Force Approach. Simple, straight forward and slow, time: O(n^2)?
    int lengthOfLongestSubstring_v3(string s) {
        int result = 0;
        string currSubstr;

        size_t pos = 0;
        while (pos != s.size()) {

            for (size_t i = pos; i != s.size(); ++i) {
                if (currSubstr.find(s[i]) != string::npos) {
                    break;
                }
                currSubstr.push_back(s[i]);
            }

            if (currSubstr.size() > result) {
                result = static_cast<int>(currSubstr.size());
            }

            ++pos; currSubstr = "";
        }

        return result;
    }
};



/* main.cpp
#include <iostream>
#include "./medium/3.longest_substr_without_repeating_chars.cpp"

int main()
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
}
*/

/*
Given a string s, find the length of the longest
substring
 without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/
