c++ -Wall -Wextra -Werror -g gen.cpp -o gen
./gen 1000 > in.txt
c++ -Wall -Wextra -Werror -g brut.cpp -o brut
time (./brut < in.txt > brut.txt)
c++ -Wall -Wextra -Werror -g real.cpp -o real
time (./real < in.txt > real.txt)
diff -w real.txt brut.txt