CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = client.c server.c
NAME = $(SRC:.c=)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re