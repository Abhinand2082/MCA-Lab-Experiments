#!/bin/bash
 
# Function to print Fibonacci Sequence
function print_fibonacci() {
    num=$1
    a=0
    b=1 
    echo "The Fibonacci sequence for $num terms is: "
 
    for (( i=0; i<num; i++ ))
    do
        echo -n "$a "
        fn=$((a + b))
        a=$b
        b=$fn
    done
}
 
# Main script
read -p "Enter the total number of Fibonacci terms: " total_terms
print_fibonacci $total_terms
