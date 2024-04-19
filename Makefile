NAME = server
NAME_2 = client


CFLAGS = -Wall -Wextra -Werror
SRCS =  utils.c server.c
SRCC =  utils.c client.c
OBGS = $(SRCS:.c=.o)
OBGC = $(SRCC:.c=.o)
OBGSB = $(SRCSB:.c=.o)
OBGCB = $(SRCCB:.c=.o)
all : $(NAME) $(NAME_2)

$(NAME): $(OBGS)
	$(CC) $(CFLAGS) $(OBGS) -o $(NAME)

$(NAME_2): $(OBGC)
	$(CC) $(CFLAGS) $(OBGC) -o $(NAME_2)
    
clean:
	rm -f $(OBGS) $(OBGC) $(OBGSB) $(OBGCB) 

fclean: clean
	rm -f $(NAME) $(NAME_2) $(NAME_3) $(NAME_4)  

re: fclean all