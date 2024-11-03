
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'
make re
if find . -name "libft.a" | grep -q "libft.a"; then
    echo -e "${GREEN}libft.a built! Executing tests...${RESET}"
    echo "Cloning 'therappha's libftester'"
    git clone https://github.com/therappha/libftester.git
    echo "bulding tests..."
    ./libftester/make
    ./libftester/test
    cd ..
    echo "Deleting libftester!..."
    rm -rf libftester
    make fclean
else
    echo -e "${RED}Error: libft.a not found!${RESET}"
fi
