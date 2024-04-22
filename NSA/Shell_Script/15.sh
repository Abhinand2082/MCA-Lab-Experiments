#!/bin/bash

dec_val_int=64836
n=$dec_val_int
val=0
power=1
while [ $n -ne 0 ]
       do
        r=`expr $n % 2`
        val=`expr $r \* $power + $val`
        power=`expr $power \* 10`
        n=`expr $n \/ 2`
        echo "n= $n" 
      done
echo "dec_val_int= $dec_val_int"
echo "Binary equivalent=$val"