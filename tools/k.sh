#!/bin/sh


<<COMMENTOUT
実験用
COMMENTOUT






echo "">LOG/SCORE.txt


for rho in 0.003 0.01 0.04 0.1; do
    for NX in 5 10 15 20 25;do
        for program in now;do
            g++ -std=gnu++17  -Wextra -O2 -DONLINE_JUDGE -D=LOCAL -Wl,-stack_size -Wl,0x11110000 -o k.out ../httf/$program.cpp

            log=LOG/"error_($rho)_($program)".txt
            echo "">$log
            cargo run --release --bin gen seeds.txt --sigma=$rho

            for file in `ls in` ;do
                cargo run --release --bin tester ./k.out $NX < in/$file >out/$file 2>>$log
            done

            SUM=0
            while read line
            do
              hoge=`echo $line | cut -c 1-5`
              if [ "$hoge" = "Score" ];then
                score=`echo $line |cut -c 9-`
                SUM=$(($SUM + $score))
              fi
              
              if [ "$hoge" = "Asser" ];then
                SUM=-1000000000000;
              fi;
            done < $log
            echo "$SUM : $NX $rho $program">>LOG/SCORE.txt
        done
    done
done
echo "">>LOG/SCORE.txt

