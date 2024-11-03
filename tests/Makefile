CC = cc
CFLAGS = -Wall -Wextra  -L. -lft
TARGET = tests
SRCS = $(wildcard *.c)

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS)

clean:
	rm -f $(TARGET)

re:	clean all


.PHONY: all, clean, re
