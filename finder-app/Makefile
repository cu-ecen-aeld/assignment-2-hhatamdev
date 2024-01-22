
CFLAGS = -g -Wall -std=c99

SOURCES = writer.c utils.c
OBJECTS = $(SOURCES:.c=.o)
#TARGET = writer
LFLAGS = 
CC ?= gcc
PREFIX ?= 

ifeq ($(CROSS_COMPILE), 1)         
	CC := aarch64_be-none-linux-gnu-gcc
	PREFIX := aarch64_
endif                             

all: writer 

writer: $(OBJECTS)
	@echo "Building writer with $(CC)"
	$(CC) $(CFLAGS) -o $(PREFIX)$@ $^ $(LFLAGS)

clean:
	@rm -f writer aarch64_writer $(OBJECTS)

    	
