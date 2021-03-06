# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kstallen <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/13 16:57:49 by kstallen       #+#    #+#                 #
#    Updated: 2020/03/10 13:55:16 by kstallen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
AR = ar rcs
IDIR = inc
CFLAGS = -g -Wall -Wextra -Werror -I $(IDIR)

HDR = $(IDIR)/ft_printf.h
SRC = ft_printf.c populate.c print1.c print2.c print_utils.c utils.c libft.c \
print_di.c print_di_minus.c print_hex.c print_lu.c print_utils.c
ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

vpath %.c src

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^

$(ODIR)/%.o: %.c $(HDR)
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(ODIR)

fclean: clean
	@$(RM) $(NAME) $(TEST_NAME)

test: all test.c
	gcc -Wall -Werror -Wextra test.c -L. -no-pie libftprintf.a

re: fclean all

.PHONY: clean fclean
