#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'  # Reset color

# Display making file message
echo -e "${GREEN}Making file...${RESET}"

d
make


if find . -name "libft.a" | grep -q "libft.a"; then
    echo -e "${GREEN}libft.a found! Executing tests...${RESET}"
    # Execute your test command here, for example:
    # ./your_test_program
else
    echo -e "${RED}Error: libft.a not found!${RESET}"
fi
