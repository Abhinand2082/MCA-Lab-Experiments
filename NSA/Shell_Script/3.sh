#!/bin/bash
echo "Enter a number:"
read num
r=$((num%2))
#echo "$r"
if [ $num -eq 0 ]
then
    echo "number is neither even nor odd"
elif [ $r -eq 0 ]
then
    echo "number is  even"
else
    echo "number is odd" 
fi
