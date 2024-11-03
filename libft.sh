#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'  # Reset color

# Display making file message
echo -e "${GREEN}Making libft...${RESET}"
make


if find . -name "libft.a" | grep -q "libft.a"; then
    echo -e "${GREEN}built libft.a suscessfully! Executing tests...${RESET}"
	


else
    echo -e "${RED}Error: libft.a not found, test failed!${RESET}"
fi
