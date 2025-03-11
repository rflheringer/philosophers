NAME: = philo
CCFLAGS: = -Wextra -Wall -Werror -g3

HEADERS: = -I.
SRCS:	=	inits.c \
			main.c \
			utils.c \
			validate.C

OBJS = $(SRCS:%.c=%.o)
