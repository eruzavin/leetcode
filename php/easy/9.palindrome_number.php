<?php

/**
 * @param Integer $x
 * @return Boolean
 */
function isPalindrome($x) {
    $array = str_split($x);
    
    $i = 0;
    $j = count($array) - 1;
    while ($i < $j) {
        if ($array[$i] !== $array[$j]) {
            return false;
        }
        ++$i;
        --$j;
    }
    
    return true;
}

var_dump(isPalindrome(1212));