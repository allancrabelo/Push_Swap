#!/bin/bash

BIN=./push_swap
VALGRIND="valgrind --leak-check=full --error-exitcode=42 --log-file=valgrind.log"

tests=(
  "1 2 3"
  "3 2 1"
  "1 1 2"
  "a b c"
  "1 a 2"
  "   1    2   3  "
  "+42"
  "--1"
  "2147483648"
  "-2147483649"
  "1 2 -"
  ""
  " "
  "1 2" "3 4"
  "\"1\" \"\" \"2\""
  "a"
)

echo "🔍 Leak Tester para ./push_swap"
echo "=============================="

run_test() {
	local input="$1"

	eval $VALGRIND $BIN $input > /dev/null 2>&1

	if grep -q "definitely lost: [^0]" valgrind.log; then
		echo "[KO] Leak detectado em: $input"
		grep "definitely lost" valgrind.log
	else
		echo "[OK] Sem leaks: $input"
	fi
}

for test in "${tests[@]}"; do
	run_test "$test"
done

rm -f valgrind.log
