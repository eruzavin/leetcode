<?php

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
 */

class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    // Runtime: beats 90,88%, memory: beats 11,75%
    function longestCommonPrefix($strs) {
        $res = '';
        $i = 0;
        while (true) {
            $letter = $strs[0][$i];
            foreach ($strs as $str) {
                if (($i >= strlen($str)) || ($letter != $str[$i])) {
                    return $res;
                }
            }
            $res .= $letter;
            ++$i;
        }
    }
    
    // Runtime: beats 68,77%, memory: beats 11,75%
    function longestCommonPrefix_v2($strs) {
        $res = "";
        $wordsNum = count($strs);
        $i = 0; // index of a letter
        while (true) {
            $letter = $strs[0][$i];
            for ($j = 0; $j < $wordsNum; ++$j) { // index of a word
                if (($i >= strlen($strs[$j])) || ($letter !== $strs[$j][$i])) {
                    return $res;
                }
            }
            $res .= $letter;
            ++$i;
        }
    }
}

echo 'result: ', (new Solution())->longestCommonPrefix(['flower', 'flow', 'flight']), PHP_EOL;
