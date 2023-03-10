#!/bin/bash

echo "Enter five numbers: "

read num1
read num2
read num3
read num4
read num5

sum=$(($num1 + $num2 + $num3 + $num4 + $num5))
avg=$(echo "scale=2; $sum / 5" | bc)

echo "Sum of the numbers is: $sum"
echo "Average of the numbers is: $avg"
