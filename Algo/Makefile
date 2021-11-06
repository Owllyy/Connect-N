NAME        =       player

SRCS        =       ab_prune.c \
					main.c \
					board.c \
					evaluation.c \
					
OBJS        =       ${SRCS:.c=.o}

CFLAGS      =       -Wall -Wextra -Werror -O3 -g3

CC			=		gcc

DEP			=		algo.h

%.o:%.c $(DEP)
		$(CC) ${CFLAGS} -c $< -o $@

all :   $(NAME)

clean :
	$(RM) $(OBJS)

fclean :    clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

$(NAME) :   $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY :    all fclean clean re