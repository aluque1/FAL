g++ -Wall -g $1 -o $2 && ./"$2" < e.in > e.out && cat e.out
