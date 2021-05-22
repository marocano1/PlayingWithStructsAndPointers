BINARY = funwithstructs
CC = gcc
BIN = bin
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS = $(wildcard $(SRC)/*.h)
CFLAGS = -g -Wall -Werror -Wextra

all: $(BINARY)

$(BINARY): $(OBJS) $(BIN)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)/$@

$(BIN):
	mkdir -p $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm $(OBJ)/*
	rm -r $(BIN)
