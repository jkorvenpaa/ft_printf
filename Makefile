NAME = libftprintf.a
COMPILER = cc
COPILERFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = ft_printf.c \
		ft_helper.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_decimal.c \
		ft_undecimal.c \
		ft_converthex.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@

clean:
		@rm -f *.o
		@echo "removing object files"

fclean: clean
		@rm -f $(NAME)
		@echo "removing executable file"

re: fclean all

.PHONY: all clean fclean re