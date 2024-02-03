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
ARG="42 69 85 14 84 74 1 36 35 43 19 29 60 64 66 59 38 75 76 80 51 40 56 21 25 9 52 90 3 47 5 78 55 79 88 62 68 20 63 94 4 61 71 17 16 99 23 34 33 41 93 37 96 91 39 48 12 53 22 77 30 58 15 8 27 46 11 65 92 50 18 2 100 13 82 87 70 54 95 24 7 45 32 44 6 86 28 26 89 31 57 98 81 72 10 73 97 67 49 83"
echo \>Test10: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="35 53 63 49 86 83 81 14 96 77 4 28 42 88 100 30 51 58 24 34 7 62 48 92 36 57 93 31 6 73 45 94 95 68 39 9 80 33 1 97 91 67 69 19 16 5 60 22 85 32 2 25 29 98 11 17 64 59 13 99 74 40 43 79 21 12 84 44 3 10 37 26 61 50 23 75 15 20 87 65 82 47 55 72 46 76 70 71 18 66 90 78 41 56 54 8 38 89 52 27"
echo \>Test11: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="63 82 9 93 11 1 38 28 30 61 52 91 14 97 67 94 74 5 87 98 49 58 55 16 10 33 34 18 32 44 7 12 73 79 24 86 51 70 77 19 60 23 17 6 41 59 89 36 43 88 29 21 90 4 78 64 46 31 3 71 68 76 37 45 40 75 27 2 47 50 92 35 22 66 42 53 72 57 56 80 13 65 8 26 15 39 25 100 81 54 69 96 95 84 20 85 62 83 48 99"
echo \>Test12: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="22 77 16 66 83 40 90 29 52 21 68 35 70 81 2 100 20 27 46 7 42 31 84 39 33 87 1 92 80 23 32 67 41 59 51 34 82 3 37 43 76 53 50 18 5 55 91 44 36 89 45 6 26 98 8 19 10 15 56 17 93 78 79 24 99 71 74 48 65 64 47 88 49 28 63 95 13 4 25 94 58 97 9 11 54 85 60 86 57 14 73 62 30 38 72 12 96 61 69 75"
echo \>Test13: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="44 70 96 53 98 56 42 50 5 17 99 69 57 13 35 67 51 45 78 8 100 75 89 1 23 74 52 27 59 84 46 25 40 14 49 88 68 81 20 63 73 34 80 97 2 61 79 36 18 24 60 71 83 93 32 28 87 30 82 11 94 54 9 65 64 91 92 66 3 77 6 16 7 31 62 95 76 47 55 58 26 90 12 85 37 38 33 48 29 41 19 4 21 15 39 22 43 10 86 72"
echo \>Test14: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="69 62 24 93 18 59 45 25 51 54 74 47 66 30 86 95 37 98 100 42 13 89 80 12 28 15 71 60 40 57 6 48 82 94 32 96 50 52 16 41 78 22 4 61 63 49 8 68 44 11 75 17 1 99 81 23 39 83 77 43 73 19 70 65 2 21 35 3 14 91 29 55 31 5 72 34 33 84 56 20 85 76 46 10 67 88 97 64 58 87 92 7 9 26 38 53 90 36 79 27"
echo \>Test15: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="9 71 40 21 97 19 34 60 92 66 41 68 15 11 74 48 100 62 26 5 17 80 90 1 37 69 33 8 54 28 55 30 83 4 79 57 99 2 93 49 64 18 65 95 32 43 86 91 51 88 56 24 87 29 81 77 73 96 20 84 7 98 47 14 22 50 36 58 25 13 76 82 75 78 44 45 27 94 31 52 59 38 6 61 42 72 12 10 23 39 70 35 3 85 63 53 46 16 67 89"
echo \>Test16: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="4 0 2 3 1"
echo \>Test17: $ARG piped to checker\<
./push_swap $ARG
./push_swap $ARG | ./checker $ARG
echo -----------
echo +++++++++++
echo -----------
ARG="0 3 7 8 2 6 4 1 5 9"
echo \>Test18: new alg considerations \for 0 3 7 8 2 6 4 1 5 9\<
echo \>Sketch: \if \< size / 2, ra; \else pb\<
echo 1st round of steps: rra pb ra ra sa pb pb
echo Result =\> A: 2 6 4 1 5 0 3;   B: 7 8 9;
echo 2nd round of steps: ra pb ra sa pb
echo Result =\> A: 1 0 3 2 4;   B: 5 6 7 8 9;
echo 3rd round of steps: sa rra rra rra sa 
echo Result =\> A: 2 3 4 0 1;   B: 5 6 7 8 9;
echo 4th round of steps: rra rra pa ra pa ra pa ra pa ra pa ra
echo Result =\> A: 0 1 2 3 4 5 6 7 8 9;   B: - ;
echo Total steps: 29
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 2 steps.
echo ___________
ARG="0 3 7 8 2 6 4 1 5 9"
echo \>Test19: new alg considerations \for 0 3 7 8 2 6 4 1 5 9\<
echo \>Sketch: \if \(topofA \> \(size / 2\)\), ra; \else pb\<
echo 1st round of steps: pb pb rra rra rra pb sb
echo Result =\> A: 5 9 7 8 2 6 4; B: 3 1 0;
echo 2nd round of steps: rra pb rra rra
echo Result =\> A: 2 6 5 9 7 8; B: 4 3 1 0;
echo 3rd round of steps: pb ss
echo Result =\> A: 5 6 9 7 8;   B: 4 2 3 1 0
echo 4th round of steps now that equal sizes, RA-SIFTING AND SWAPPING JE NACH A/B STACK DIRECTION: rr sb
echo Result =\> A: 6 7 9 8 5;   B: 3 2 1 0 4
echo 5th round of steps continued SIFTING \until 'sorted': rr rr sa
echo Result =\> A: 8 9 5 6 7;   B: 1 0 4 3 2
echo 6th round of steps \until \in position: rr rr
echo Result =\> A: 5 6 7 8 9;   B: 4 3 2 1 0
echo 7th round of steps pa \until all \done: pa pa pa pa pa
echo Result =\> A: 0 1 2 3 4 5 6 7 8 9
echo Total steps: 25
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 2 steps.
echo ___________
ARG="5 3 8 2 4 1 0 9 6 7"
echo \>Test20: same alg as Test19, \let\'s look at it. 5 3 8 2 4 1 0 9 6 7
echo \>Sketch: \if \(topofA \> \(size / 2\)\), ra, \else pb. sa \where needed\. \if a[z] value adjacent to a[0] value, or b[z] to b[0], get proactive at any step. Or both \if both.\<
echo 1st round of steps: ra pb ra pb sb pb pb rb pb rb
echo Result =\> A: 9 6 7 5 8;   B: 4 3 2 1 0;
echo 2nd round of steps: now that equal sizes, RA-SIFTING AND SWAPPING JE NACH DIRECTION: ra ra sa rra sa
echo Result =\> A: 5 6 7 8 8;   B: 4 3 2 1 0;
echo 3rd round of steps pa \until all \done: pa pa pa pa pa
echo Total steps: 20
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 8 steps.
echo ___________
ARG="1 2 0 3 4"
echo \>Test21: same alg as Test19 and Test20, \let\'s look at it. 1 2 0 3 4
echo 1st round of steps: pb pb pb rb pa pa pa
echo Total steps: 7
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 3 steps.
echo ___________
ARG="2 3 4 1 0"
echo \>Test22: same alg as Test19 thru Test21, \let\'s look at it. 2 3 4 1 0
echo according to previous definitions: ra ra ra sa --- oops unexpected solve, was getting ready to pb!
echo INNOVATION - \if it can be solved by swaps only: ra ra ra sa
echo Total steps: 4
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 1 steps.
echo ___________
ARG="2 1 3 4 0"
echo \>Test23: same alg as Test19 thru here, \let\'s look at it. 2 1 3 4 0
echo according to previous definitions: 
echo INNOVATION - \if it can be solved by swaps only: ra ra ra sa
echo Total steps: 4
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 1 steps.
echo ___________
