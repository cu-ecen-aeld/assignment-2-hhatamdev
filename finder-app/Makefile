
CFLAGS = -g -Wall -std=c99

SOURCES := $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
#TARGET = writer
LFLAGS = 
CC ?= gcc
PREFIX ?= 

ifeq ($(CROSS_COMPILE), 1)         
	CC := aarch64_be-none-linux-gnu-gcc
	PREFIX := aarch64_
	@echo "cc:$(CC), prefix:$(PREFIX)"
endif                             

all: writer 

writer: $(OBJECTS)
	@echo "Building writer with $(CC)"
	$(CC) $(CFLAGS) -o $(PREFIX)$@ $^ $(LFLAGS)

clean:
	@rm -f writer $(PREFIX)_writer $(OBJECTS)

    	
