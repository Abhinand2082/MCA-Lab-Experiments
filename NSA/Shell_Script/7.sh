#!/bin/bash
echo "Eneter a number:"
read n
for i in {1..10};do
echo "$n*$i=$((n*i))"
done
