# Makefile for cpp-lab

B = build
S = src
I = include

CC = clang++
CFLAGS = -std=c++14
CFLAGS += -Wall -O2 -D_GNU_SOURCE
CFLAGS += -I$I

FORMAT = clang-format
FFLAGS = --style=google -i

SRC = $(shell echo $S/*.cc)
HEADER = $(shell echo $I/*.h)
TARGET = $B/app

$(TARGET): $(SRC) $(HEADER)
	@if [ ! -d $B ]; then mkdir $B; fi
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $B

format:
	$(FORMAT) $(FFLAGS) $S/*
	$(FORMAT) $(FFLAGS) $I/*
