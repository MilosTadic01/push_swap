#!/bin/zsh

ARG="-1 INT_MIN 0 42 22"
echo \>Test1: $ARG\<
./push_swap $ARG
echo ___________
ARG=""
echo \>Test2: $ARG\<
./push_swap $ARG
echo ___________
ARG='-1 INT_MIN 0 42 22'
echo \>Test3: $ARG\<
./push_swap $ARG
echo ___________
ARG="-1 "INT_MIN 0 " 42 22"
echo \>Test4: $ARG\<
./push_swap $ARG
echo ___________
ARG="INT_MAX 0 1 2"
echo \>Test5: $ARG\<
./push_swap $ARG
echo ___________
ARG="1 two 3"
echo \>Test6: $ARG\<
./push_swap $ARG
echo ___________
ARG="1 2 3"
echo \>Test7: $ARG\<
./push_swap $ARG
echo ___________
ARG="1"
echo \>Test8: $ARG\<
./push_swap $ARG
echo ___________
ARG="" 1""
echo \>Test9: $ARG\<
./push_swap $ARG
echo ___________
