set -e # stop the script when a command (line) fails

gen_src=gen.cpp
brute_src=2180C_brute.cpp
code_src=2180C_upsolve_but_high_rated.cpp
checker=checker.cpp

echo	$code_src "compilation ..."
g++		$code_src -o code

echo	$gen_src "compilation ..."
g++		$gen_src -o gen

echo	$brute_src "compilation ..."
g++		$brute_src -o brute

echo	$checker "compilation ..."
g++		$checker -o checker

for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    ./checker || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
