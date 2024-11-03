
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'

echo -e "${GREEN}Making file...${RESET}"
make re

if find . -name "libft.a" | grep -q "libft.a"; then
    echo -e "${GREEN}libft.a built! Executing tests...${RESET}"
    ./libftester/make
else
    echo -e "${RED}Error: libft.a not found!${RESET}"
fi
