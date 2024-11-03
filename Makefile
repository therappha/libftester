LIBFT_SRC ?= $(shell pwd)
CC = cc
CFLAGS = -Wall -Wextra
INCLUDES = $(LIBFT_SRC)
TARGET = test
SRCS = $(wildcard tests/*.c)

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) -I $(INCLUDES) $(CFLAGS) -L$(LIBFT_SRC) -lft

clean:
	rm -f $(TARGET)

re:	clean all


.PHONY: all, clean, re
