#!/bin/bash
echo "Enter 2 numbers(Space Seperated)"
read num1 num2
sum=$((num1+num2))
dif=$((num1-num2))
pro=$((num1*num2))
quo=$((num1/num2))
echo "Sum:$sum"
echo "Difference:$dif"
echo "Product:$pro"
echo "Quotient:$quo"
