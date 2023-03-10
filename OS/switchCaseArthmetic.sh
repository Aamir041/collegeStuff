#!/bin/bash

echo "Select an operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice

echo "Enter two numbers:"
read num1
read num2

case $choice in
    1) result=$(($num1 + $num2))
       echo "The sum of $num1 and $num2 is $result." ;;
    2) result=$(($num1 - $num2))
       echo "The difference between $num1 and $num2 is $result." ;;
    3) result=$(($num1 * $num2))
       echo "The product of $num1 and $num2 is $result." ;;
    4) if [ $num2 -eq 0 ]; then
           echo "Error: division by zero."
       else
           result=$(($num1 / $num2))
           echo "The quotient of $num1 and $num2 is $result."
       fi ;;
    *) echo "Invalid choice. Please select an option between 1 and 4." ;;
esac
