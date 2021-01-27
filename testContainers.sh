#! /bin/sh
BLUE=$'\e[0;36m'
NC=$'\e[0m'

echo "~ Makefile is compiling ~\n";
make re
rm -rf results/*_diff.txt
./containers_test

echo "~ Test diff output from std::vector and your work ~";
if diff results/vector_ft.txt results/vector_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/vector_ft.txt results/vector_std.txt > results/vector_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "~ Test diff output from std::list and your work ~";
if diff results/list_ft.txt results/list_std.txt > /dev/null;then
    echo "${BLUE}No differences${NC}";
else 
	diff results/list_ft.txt results/list_std.txt > results/list_diff.txt
    echo "${BLUE}Try again${NC}";
fi

echo "";
make fclean
