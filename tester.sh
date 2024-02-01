ARG="4 3 0 1 2"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG=""
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG="-1 \"INT_MIN 0 \" 42 22"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG="INT_MAX 0 1 2"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG="1 two 3"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG="1 2 3"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG="1"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
ARG=" 1"
echo \>Test $ARG\<
./push_swap $ARG
echo ___________
