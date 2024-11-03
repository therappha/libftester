LIBFT_SRC ?= $(shell pwd)
LIBFT  = $(LIBFT_SRC)/libft.a
CC = cc
CFLAGS = -Wall -Wextra
INCLUDES = includes/
TARGET = test
SRCS = $(wildcard tests/*.c)

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) -I $(INCLUDES) $(CFLAGS) -L$(LIBFT_PATH) -lft

clean:
	rm -f $(TARGET)

re:	clean all


.PHONY: all, clean, re
