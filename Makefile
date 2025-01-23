CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = client.c server.c
NAME = $(SRC:.c=)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:

fclean:
	rm -f $(NAME) 

re: 
	fclean all

.PHONY: all clean re fclean