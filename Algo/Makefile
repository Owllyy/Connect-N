NAME        =       player

SRCS        =       ab_prune.c \
					main.c \
					board.c \
					evaluation.c \
					node_count.c \
					open_close.c \
					parse.c \
					timer.c
					
OBJS        =       ${SRCS:.c=.o}

CFLAGS      =       -Ofast -g3 -march=native

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