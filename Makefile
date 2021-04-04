NAME = libftprintf.a

SRCS = ft_printf.c \
			srcs/convert_base.c \
			srcs/ft_parse_dot.c \
			srcs/ft_parse_flag.c \
			srcs/ft_parse_minus.c \
			srcs/ft_parse_star.c \
			srcs/ft_parse_type.c \
			srcs/ft_putnbr.c \
			srcs/ft_treat_hexa_minus_space_prec.c \
			srcs/ft_treat_hexa_zero_space_prec.c \
			srcs/ft_treat_hexa.c \
			srcs/ft_treat_int_dot_space_prec.c \
			srcs/ft_treat_int_dot.c \
			srcs/ft_treat_int_minus_space_prec.c \
			srcs/ft_treat_int_zero_space_prec.c \
			srcs/ft_treat_int.c \
			srcs/ft_treat_string_minus_space_prec.c \
			srcs/ft_treat_string_minus_space_prec2.c \
			srcs/ft_treat_u_dot_space_prec.c \
			srcs/ft_treat_u_dot_space.c \
			srcs/ft_treat_u_minus_space_prec.c \
			srcs/ft_treat_u_zero_space_prec.c \
			srcs/ft_treatment_flag_digit.c \
			srcs/ft_treatment_flag_dot.c \
			srcs/ft_treatment_flag_star.c \
			srcs/ft_treatment_percent.c \
			srcs/ft_treatment_type_dot_hexa_utils.c \
			srcs/ft_treatment_type_dot_hexa.c \
			srcs/ft_treatment_type_dot_int.c \
			srcs/ft_treatment_type_dot_pointer.c \
			srcs/ft_treatment_type_dot_string.c \
			srcs/ft_treatment_type_dot_u.c \
			srcs/ft_treatment_type_dot.c \
			srcs/ft_treatment_type_minus.c \
			srcs/ft_treatment_type_number.c \
			srcs/ft_treatment_type.c \
			srcs/ft_u_itoa.c \
			srcs/ft_utils.c \
			srcs/ft_parse_type_zero.c \
			srcs/ft_parse_type_dot_space_prec.c \
			srcs/ft_parse_flag2.c \
			srcs/ft_parse_minus2.c \
			srcs/ft_utils_isdigit_minus.c \
			srcs/ft_parse_zero.c

FLAGS = -c -Wall -Wextra -Werror -I./includes

CC = gcc $(FLAGS)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
