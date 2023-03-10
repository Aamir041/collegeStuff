#!/bin/bash

echo "Enter three numbers:"
read num1
read num2
read num3

# Find the largest number
if [ $num1 -ge $num2 ] && [ $num1 -ge $num3 ]; then
    largest=$num1
elif [ $num2 -ge $num1 ] && [ $num2 -ge $num3 ]; then
    largest=$num2
else
    largest=$num3
fi

# Find the smallest number
if [ $num1 -le $num2 ] && [ $num1 -le $num3 ]; then
    smallest=$num1
elif [ $num2 -le $num1 ] && [ $num2 -le $num3 ]; then
    smallest=$num2
else
    smallest=$num3
fi

echo "The largest number is $largest."
echo "The smallest number is $smallest."
