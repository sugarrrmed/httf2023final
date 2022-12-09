#!/bin/sh

g++ -std=gnu++17  -Wextra -O2 -DONLINE_JUDGE -D=LOCAL -Wl,-stack_size -Wl,0x11110000 httf/main.cpp -o main.out


if test $# -eq 0 ; then

for file in `ls httf/IN` ;do
    echo "---------------"$file"--------------------"
    ./main.out < httf/IN/$file > httf/OUT/$file
done

else
num=$1 #1番目の引数

    if [ $num -eq -1 ] ; then
        for num in 0 1 2 3 4;do
        file=$(printf "%04d" ${num}).txt
        echo "--------------"$file"--------------"
        ./main.out < httf/IN/$file > httf/OUT/$file
        done
    
    else
    
        file=$(printf "%04d" ${num}).txt
        echo "--------------"$file"--------------"
        ./main.out < httf/IN/$file > httf/OUT/$file
    fi
    
fi


rm main.out

<<comment

引数が0なら全ケース実施
引数が何かあれば1つだけ

coment
