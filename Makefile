TARGET := PATTERN
CC     := g++
CFLAGS := -Wall -Wextra -Weffc++ -pedantic -std=c++11 -g

SRCS := pattern.cpp init.cpp
HDRS := pattern.h

all: build
	@echo "Compilation complete."

build:
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)
