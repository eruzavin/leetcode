<?php

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        if ($s === '') {
            return 0;
        }

        $dict = array_fill(0, 256, -1);
        $maxLen = 0;
        $start = -1;

        $charsArray = str_split($s);

        foreach ($charsArray as $i => $char) {
            $ascii = ord($char);
            if ($dict[$ascii] > $start) {
                $start = $dict[$ascii];
            }

            $dict[$ascii] = $i;

            $maxLen = max($maxLen, $i - $start);
        }

        return $maxLen;
    }
}

$s = new Solution();
echo $s->lengthOfLongestSubstring('abc'), PHP_EOL;