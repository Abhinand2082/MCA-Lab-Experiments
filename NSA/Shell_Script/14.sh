#!/bin/bash

calculate_sum_of_squares() {
  local n=$1
  local sum=0
  local i=1

  while [ $i -le $n ]; do
    sum=$((sum + i*i))
    i=$((i + 1))
  done

  echo $sum
}

echo "Enter a number:"
read n

result=$(calculate_sum_of_squares $n)
echo "Sum of squares: $result"