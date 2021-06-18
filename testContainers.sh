#! /bin/sh
BLUE=$'\e[0;36m'
RED=$'\e[0;31m'
GREEN=$'\e[32m'
NC=$'\e[0m'

echo "~ Makefile is compiling ~\n";
make re
rm -rf results/*_diff.txt
./containers_test

echo "Test diff output from ${BLUE}std::vector${NC} and your work: \c";
if diff results/vector_ft.txt results/vector_std.txt > /dev/null;then
    echo "${GREEN}No differences${NC}";
else
	diff results/vector_ft.txt results/vector_std.txt > results/vector_diff.txt
    echo "${RED}Try again${NC}";
fi

echo "Test diff output from ${BLUE}std::list${NC} and your work: \c";
if diff results/list_ft.txt results/list_std.txt > /dev/null;then
    echo "${GREEN}No differences${NC}";
else
	diff results/list_ft.txt results/list_std.txt > results/list_diff.txt
    echo "${RED}Try again${NC}";
fi

echo "Test diff output from ${BLUE}std::stack${NC} and your work: \c";
if diff results/stack_ft.txt results/stack_std.txt > /dev/null;then
    echo "${GREEN}No differences${NC}";
else
	diff results/stack_ft.txt results/stack_std.txt > results/stack_diff.txt
    echo "${RED}Try again${NC}";
fi

echo "Test diff output from ${BLUE}std::queue${NC} and your work: \c";
if diff results/queue_ft.txt results/queue_std.txt > /dev/null;then
    echo "${GREEN}No differences${NC}";
else
	diff results/queue_ft.txt results/queue_std.txt > results/queue_diff.txt
    echo "${RED}Try again${NC}";
fi

echo "Test diff output from ${BLUE}std::map${NC} and your work: \c";
if diff results/map_ft.txt results/map_std.txt > /dev/null;then
    echo "${GREEN}No differences${NC}";
else
	diff results/map_ft.txt results/map_std.txt > results/map_diff.txt
    echo "${RED}Try again${NC}";
fi

make fclean
