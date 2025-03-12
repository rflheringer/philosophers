NAME = philo

CCFLAGS = -Wextra -Wall -Werror -g3

HEADERS = -I. -pthread

SRCS	=	philo/basic.c \
			philo/basic2.c \
			philo/free.c \
			philo/inits.c \
			philo/main.c \
			philo/monitoring.c \
			philo/status.c \
			philo/time.c \
			philo/utils.c \
			philo/validate.c \
			philo/free.c

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
