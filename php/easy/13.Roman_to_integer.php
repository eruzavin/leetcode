<?php

/**
 * @param String $s
 * @return Integer
 */
function romanToInt($s) {
    $NumsMap = [
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000
    ];
    
    $array = str_split($s);
    $strSize = count($array);
    
    $res = $NumsMap[$array[$strSize - 1]];
    
    for ($i = 1; $i < $strSize; ++$i) {
        $prevNum = $NumsMap[$array[$i - 1]];
        $currNum = $NumsMap[$array[$i]];
        
        if ($prevNum < $currNum) {
            $res -= $prevNum;
        } else {
            $res += $prevNum;
        }
    }
    
    return $res;
}

echo romanToInt('MCMXCIV'), PHP_EOL;
