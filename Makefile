NAME = libftprintf.a

INC = ./includes/ft_printf.h

SRC = ./src/ft_calc_hex_length.c ./src/ft_printf.c \
	./src/ft_decimal_to_hex.c ./src/ft_itoa.c \
	./src/ft_print_hex_int.c ./src/ft_print_pointer.c \
	./src/ft_print_unsigned.c ./src/print_utils.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

${NAME}: ${OBJ} ${OBJ_src}
	ar -rcs ${NAME} ${OBJ} ${OBJ_src} ${INC}

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJ} ${OBJ_src}

fclean: clean
	${RM} ${NAME}

re: fclean all
