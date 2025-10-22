set -e # stop the script when a command (line) fails

gen_src = gen.cpp
brute_src = brute.cpp
code_src = code.cpp

g++ $code_src -o code
g++ $gen_src -o gen
g++ $brute_src -o brute

for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
