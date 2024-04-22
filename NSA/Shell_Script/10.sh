#!/bin/bash
while true;do
    echo "MENU"
    echo "1.Sum"
    echo "2.Difference"
    echo "3.Product"
    echo "4.Quotient"
    echo "0.Exit"
    echo "Enter your choice:"
read choice
case $choice in
    1)
     echo "Enter 2 numbers(Space Seperated)"
     read num1 num2
     sum=$((num1+num2))
     echo "Sum is:$sum"
    ;;
    2)
     echo "Enter 2 numbers(Space Seperated)"
     read num1 num2
     dif=$((num1-num2))
     echo "Difference is:$quo"
    ;;
    3)
     echo "Enter 2 numbers(Space Seperated)"
     read num1 num2
     pro=$((num1*num2))
     echo "Product is:$pro"
    ;;
    4)
     echo "Enter 2 numbers(Space Seperated)"
     read num1 num2
     quo=$((num1/num2))
     echo "Quotient is:$quo"
    ;;
    0)
     echo "Exiting Program"
     exit
     ;;
    *)
      echo "Invalid Choice"
    ;;
esac
done   
