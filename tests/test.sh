#!/bin/bash

# **************************************************************************** #
#                            Push Swap Testing Script                          #
# **************************************************************************** #
# Usage: ./test_pushswap.sh [NUMS] [ITER]
# Example: ./test_pushswap.sh 100 10

# **************************************************************************** #
#                                 Program Setup                                #
# **************************************************************************** #

PUSHSWAP="./push_swap"
CHECKER="./checker_linux"

VAR1=${1:-100}    # Default: 100 numbers
VAR2=${2:-10}     # Default: 10 iterations

# **************************************************************************** #
#                                Output Styling                                #
# **************************************************************************** #

ESC='\033['
RST='0m'

# Styles
B='1;'
D='2;'
I='3;'
U='4;'
BL='5;'
ST='9;'

# Colors
C_MAGENTA='95m'
C_RED='91m'
C_GREEN='92m'
C_YELLOW='93m'
C_BLUE='94m'

# **************************************************************************** #
#                               Program Validation                             #
# **************************************************************************** #

if [ ! -f "$PUSHSWAP" ]; then
	echo -e "${ESC}${B}${C_RED}✗ Error:${ESC}${RST} $PUSHSWAP not found"
	exit 1
fi

if [ ! -f "$CHECKER" ]; then
	echo -e "${ESC}${B}${C_RED}✗ Error:${ESC}${RST} $CHECKER not found"
	exit 1
fi

# **************************************************************************** #
#                                 Test Summary                                 #
# **************************************************************************** #

echo -e "${ESC}${B}${C_MAGENTA}▶ Push Swap Tester${ESC}${RST}"
echo -e "${ESC}${C_YELLOW}✔ Testing ${VAR1} numbers for ${VAR2} iterations${ESC}${RST}"
echo -e "${ESC}${C_BLUE}------------------------------------------------------------${ESC}${RST}"


total_moves=0
passed_tests=0
failed_tests=0
min_moves=999999
max_moves=0
ko_count=0

for ((i=1; i<=VAR2; i++)); do
	printf "\r${ESC}${C_YELLOW}→ Test $i/$VAR2${ESC}${RST}"

	numbers=$(shuf -i 1-2147483647 -n $VAR1 | tr '\n' ' ')
	push_swap_output=$($PUSHSWAP $numbers)
	move_count=$(echo "$push_swap_output" | wc -l)
	[ -z "$push_swap_output" ] && move_count=0

	checker_result=$($PUSHSWAP $numbers | $CHECKER $numbers)

	if [ "$checker_result" = "OK" ]; then
		((passed_tests++))
		total_moves=$((total_moves + move_count))
		[ $move_count -lt $min_moves ] && min_moves=$move_count
		[ $move_count -gt $max_moves ] && max_moves=$move_count
	else
		echo -e "\n${ESC}${B}${C_RED}✗ FAILED Test $i${ESC}${RST}"
		echo "Numbers: $numbers"
		echo -e "Result: ${ESC}${C_RED}KO${ESC}${RST}"
		echo -e "Output:\n$push_swap_output"
		((failed_tests++))
		((ko_count++))
	fi
done

# **************************************************************************** #
#                               Final Statistics                               #
# **************************************************************************** #

echo -e "\n${ESC}${C_BLUE}------------------------------------------------------------${ESC}${RST}"
echo -e "${ESC}${B}${C_MAGENTA}✔ FINAL RESULTS${ESC}${RST}"
echo -e "${ESC}${C_BLUE}------------------------------------------------------------${ESC}${RST}"
echo -e "Total tests: ${ESC}${C_YELLOW}$VAR2${ESC}${RST}"
echo -e "Passed     : ${ESC}${C_GREEN}$passed_tests${ESC}${RST}"
echo -e "Failed     : ${ESC}${C_RED}$failed_tests${ESC}${RST}"

if [ $passed_tests -gt 0 ]; then
	avg_moves=$((total_moves / passed_tests))
	echo -e "Average    : ${ESC}${C_YELLOW}$avg_moves moves${ESC}${RST}"
	echo -e "Min moves  : ${ESC}${C_GREEN}$min_moves${ESC}${RST}"
	echo -e "Max moves  : ${ESC}${C_RED}$max_moves${ESC}${RST}"
fi

[ $ko_count -gt 0 ] && echo -e "${ESC}${C_RED}⚠ Warning: $ko_count tests returned KO${ESC}${RST}"

# **************************************************************************** #
#                             Grade Estimation (42)                            #
# **************************************************************************** #

# Grade estimation (for 42 project)
grade_estimate() {
	if [ "$1" -eq 3 ]; then
		echo -e "\n${ESC}${B}${C_YELLOW}Grade estimation for 3 numbers:${ESC}${RST}"
		if [ "$passed_tests" -eq "$VAR2" ] && [ "$max_moves" -le 3 ]; then
			echo -e "${ESC}${B}${C_BLUE}Perfect: ≤3 operations${ESC}${RST}"
		else
			echo -e "${ESC}${B}${C_RED}Failing: >3 operations or KO result${ESC}${RST}"
		fi
	elif [ "$1" -eq 5 ]; then
		echo -e "\n${ESC}${B}${C_YELLOW}Grade estimation for 5 numbers:${ESC}${RST}"
		if [ "$passed_tests" -eq "$VAR2" ] && [ "$max_moves" -le 12 ]; then
			echo -e "${ESC}${B}${C_BLUE}Perfect: ≤12 operations${ESC}${RST}"
		else
			echo -e "${ESC}${B}${C_RED}Failing: >12 operations or KO result${ESC}${RST}"
		fi
	elif [ "$1" -eq 100 ]; then
		echo -e "\n${ESC}${B}${C_YELLOW}Grade estimation for 100 numbers:${ESC}${RST}"
		if [ "$passed_tests" -eq "$VAR2" ] && [ "$max_moves" -le 700 ]; then
			echo -e "${ESC}${B}${C_BLUE}Excellent: ≤700 moves${ESC}${RST}"
		elif [ "$max_moves" -le 900 ]; then
			echo -e "${ESC}${B}${C_GREEN}Good: ≤900 moves${ESC}${RST}"
		elif [ "$max_moves" -le 1100 ]; then
			echo -e "${ESC}${B}${C_GREEN}OK: ≤1100 moves${ESC}${RST}"
		elif [ "$max_moves" -le 1300 ]; then
			echo -e "${ESC}${B}${C_GREEN}Acceptable: ≤1300 moves${ESC}${RST}"
		elif [ "$max_moves" -le 1500 ]; then
			echo -e "${ESC}${B}${C_RED}Poor: ≤1500 moves${ESC}${RST}"
		else
			echo -e "${ESC}${B}${C_RED}Failing: >1500 moves or KO result${ESC}${RST}"
		fi
	elif [ "$1" -eq 500 ]; then
		echo -e "\n${ESC}${B}${C_YELLOW}Grade estimation for 500 numbers:${ESC}${RST}"
		if [ "$passed_tests" -eq "$VAR2" ] && [ "$max_moves" -le 5500 ]; then
			echo -e "${ESC}${B}${C_BLUE}Excellent: ≤5500 moves${ESC}${RST}"
		elif [ "$max_moves" -le 7000 ]; then
			echo -e "${ESC}${B}${C_GREEN}Good: ≤7000 moves${ESC}${RST}"
		elif [ "$max_moves" -le 8500 ]; then
			echo -e "${ESC}${B}${C_GREEN}OK: ≤8500 moves${ESC}${RST}"
		elif [ "$max_moves" -le 10000 ]; then
			echo -e "${ESC}${B}${C_GREEN}Acceptable: ≤10000 moves${ESC}${RST}"
		elif [ "$max_moves" -le 11500 ]; then
			echo -e "${ESC}${B}${C_RED}Poor: ≤11500 moves${ESC}${RST}"
		else
			echo -e "${ESC}${B}${C_RED}Failing: >11500 moves or KO result${ESC}${RST}"
		fi
	fi
}

grade_estimate "$VAR1"

echo -e "${ESC}${C_BLUE}------------------------------------------------------------${ESC}${RST}"
