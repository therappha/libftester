
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'
original_dir=$(pwd)
make re
if find . -name "libft.a" | grep -q "libft.a"; then
    echo -e "${GREEN}libft.a built! Executing tests...${RESET}"
    echo "Cloning 'therappha's libftester'"
    git clone https://github.com/therappha/libftester.git
    echo "bulding tests..."
   ( cd libftester; make test )
    (cd libftester; ./test)
    echo "Deleting libftester!..."
    cd "$original_dir"
    make fclean
    rm -rf libftester
else
    echo -e "${RED}Error: libft.a not found!${RESET}"
fi
