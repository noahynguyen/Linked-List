#!/bin/bash

rm score.txt
touch score.txt
for i in {1..27}
do
	echo "TEST" $i
	echo "TEST" $i >> score.txt
	rm test$i 2> /dev/null
	g++ -o test$i test$i.cpp animal.cpp child.cpp bird.cpp
	./test$i >> score.txt
done
echo " "
echo "FINAL SCORE::"
grep SCORE score.txt | awk '{sum+=$2;}END{print sum/2;}'
