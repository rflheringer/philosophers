NAME = philo

CCFLAGS = -Wextra -Wall -Werror -g3

HEADERS = -I. -pthread

SRCS	=	philos/basic.c \
			philos/basic2.c \
			philos/inits.c \
			philos/main.c \
			philos/monitoring.c \
			philos/status.c \
			philos/time.c \
			philos/utils.c \
			philos/validate.c \
			philos/free.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

hel: all
	valgrind \
		--tool=helgrind \
		--history-level=none \
		-s \
		./$(NAME) 5 1800 200 200 

drd: all
	valgrind \
		--tool=drd \
		-s \
		./$(NAME) 5 1800 200 200 5
#       --log-file=drd-out.txt \

clean:
	@rm -rf $(OBJS)
	# @rm -rf $(OBJS_BONUS)

fclean: clean
	@rm -rf $(NAME)
	# @rm -rf $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re
