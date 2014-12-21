CFLAGS += -Wall -std=c11

SRCFILES := $(wildcard *.c)
PROGRAMS := $(SRCFILES:.c=)

.PHONY: all clean
all: $(PROGRAMS)

%: %.c
	@echo "$< -o $@"
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f $(PROGRAMS)

