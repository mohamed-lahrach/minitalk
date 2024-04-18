	
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: client server

client: client.c
    $(CC) $(CFLAGS) -o client client.c

server: server.c
    $(CC) $(CFLAGS) -o server server.c

clean:
    rm -f client server

.PHONY: all clean