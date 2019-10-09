CC=gcc
LD=gcc

CCFLAGS= -c -O2
LDFLAGS= -O2

BIN=hl
OBJECTS:=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS:=$(wildcard *.h)


.PHONY: all clean run 


all: 
	gcc main.c -o $(BIN)


$(BIN): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJECTS): %.o : %.c $(HEADERS)
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -rf $(BIN) $(OBJECTS)
