NAME = libftGetNextLine.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rc
RM = rm -f

SRCS =	get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c 	get_next_line.h
			$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY: clean 