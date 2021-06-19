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

$(BINARY): $(BIN) $(OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)/$@

$(BIN):
	mkdir -p $@

$(OBJ):
	mkdir -p $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm -rf $(OBJ)
	rm -rf $(BIN)
