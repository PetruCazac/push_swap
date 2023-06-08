#!/bin/sh

clear

make re

echo "\n\n---- Test 1 : 1 2 3 4 5 6 7 ----\n"
if [ $? -eq 0 ]
then
	echo ./push_swap 1 2 3 4 5 6 7
	./push_swap 1 2 3 4 5 6 7
fi

echo "\n\n\n---- Test 2 : 1 2 3 3 4 5 6 7 ----\n"
if [ $? -eq 0 ]
then
	echo ./push_swap 1 2 3 3 4 5 6 7
	./push_swap 1 2 3 3 4 5 6 7
fi

echo "\n\n\n---- Test 3 : 1 2 3 4 5 6 7 in a string and a separate arg----\n"
if [ $? -eq 0 ]
then
	echo "./push_swap \"1 2 3\" 4 \"5 6\" 7"
	./push_swap "1 2 3" 4 "5 6" 7
fi

echo "\n\n\n---- Test 4 : only one value 1----\n"
if [ $? -eq 0 ]
then
	echo "./push_swap 1"
	./push_swap 1
fi

# echo "\n\n\n---- Test 5 : no value \"\"----\n"
# if [ $? -eq 0 ]
# then
# 	echo "./push_swap \"\""
# 	./push_swap ""
# fi

echo "\n\n\n---- Test 6 : 7 6 5 4 3 2 1 ----\n"
if [ $? -eq 0 ]
then
	echo ./push_swap 7 6 5
	./push_swap 7 6 5 
fi

echo "\n\n\n---- Test 7 : 1 4 89 9 32 987 6498 6688797 0 ----\n"
if [ $? -eq 0 ]
then
	echo ./push_swap 1 4 89 
	./push_swap 1 4 89 
fi