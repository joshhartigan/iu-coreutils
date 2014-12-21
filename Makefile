
CFLAGS += -Wall -std=c11 -I./include

BINDIR := bin

PROGRAMS := $(wildcard *.c)
PROGBINS := $(patsubst %.c,$(BINDIR)/%,$(PROGRAMS))

COMMONSRC := $(wildcard ./common/*.c)
COMMONOBJ := $(COMMONSRC:.c=.o)
COMMONAR := ./common.a

.PHONY: all clean
all: $(PROGBINS)

$(BINDIR):
	@mkdir $(BINDIR)

%.o: %.c
	@echo "$< -o $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(COMMONAR): $(COMMONOBJ)
	@echo "common/*.o -o ./common.a"
	@$(AR) rcs $@ $(COMMONOBJ)

$(BINDIR)/%: %.c $(COMMONAR) | $(BINDIR)
	@echo "$< -o $@"
	@$(CC) $(CFLAGS) $< $(COMMONAR) -o $@

clean:
	@rm -f $(COMMONAR)
	@rm -f $(COMMONOBJ)
	@rm -f $(PROGBINS)
	@rm -fr $(BINDIR)

