#!/bin/bash
echo "Enter 3 Marks out of 100(Space Seperated):"
read m1 m2 m3
avg=$(((m1+m2+m3)/3))
echo "Average Mark Scored:$avg"
if [ $avg -ge 90 ];then
    echo "Grade:A"
elif [ $avg -gt 79 ];then
    echo "Grade:B"
elif [ $avg -gt 59 ];then
    echo "Grade:P"
elif [ $avg -le 60 ];then
    echo "Grade:P"
fi
