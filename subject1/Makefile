NAME = Convert

SRC = $(wildcard sources/*.c)

OBJ = $(SRC:%.c=%.o)

OBJDIR = objects

HEADER = headers/convert.h

CC = gcc

.PHONY	: all clean fclean re 

all		:	$(NAME)

$(NAME)	:	$(OBJ) 
	$(CC) $(SRC) -I .$(HEADER) -o $(NAME)

%.o	:	%.c $(HEADER)
	$(CC) -c $< -o $@

clean	:
	rm -f sources/*.o

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean $(NAME)