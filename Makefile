CFLAGS += -Wall -std=c11 -I./include

SRCFILES := $(wildcard *.c)
PROGS := $(SRCFILES:.c=)

.PHONY: all clean
	all: $(PROGS)

%: %.c
	@echo "$< -o $@"
	@$(CC) $(CFLAGS) $< -o bin/$@

clean:
	rm bin/*

