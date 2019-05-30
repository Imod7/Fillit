GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

gcc main.c -I./libft/includes/ -L./libft -lft -o fillit

for i in `seq 1 17`
do
	echo "Testing tetrimino file t$i.txt"
	output="$(./fillit err_tetr/t$i.txt)"
	if grep "error" <<<"${output}" >/dev/null ; then
	 echo "${output} --> ${GREEN}Correct Result!${NC}"
	else
	 echo "${output} --> ${RED}Wrong Result!${NC}"
	fi
	echo
done
