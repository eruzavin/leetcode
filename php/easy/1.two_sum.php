<?php

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $hashTable = [];

        foreach ($nums as $i => $value) {

            $neededValue = $target - $value;
            if (isset($hashTable[$neededValue])) {
                return [$hashTable[$neededValue], $i];
            }

            $hashTable[$value] = $i;
        }
        
        return [];
    }
}

$nums = [2, 7, 11, 15];
$target = 9;

$s = new Solution();

print_r($s->twoSum($nums, $target));
