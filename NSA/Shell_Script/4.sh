#!/bin/bash
echo "Enter 3 numbers(Space Seperated):"
read n1 n2 n3
if [ $n1 -gt $n2 && $n1 -gt $n3 ];then
    echo "$n1 is larger"
elif [ $n2 -gt $n3 ];then
    echo "$n2 is larger"
else
    echo "$n3 is larger"
fi
