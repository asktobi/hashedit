CC=gcc
LD=gcc

CCFLAGS= -c -O2
LDFLAGS= -O2 -lncurses

BIN=hl
OBJECTS= hl.o find.o main.o
HEADERS:=$(wildcard *.h)


.PHONY: all clean run 


all: 
	gcc main.c -o $(BIN) -lncurses


$(BIN): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJECTS): %.o : %.c $(HEADERS)
	$(CC) $(CCFLAGS) -o $@ $<

test:
	gcc test.c -o test


clean:
	rm -rf $(BIN) $(OBJECTS) test
