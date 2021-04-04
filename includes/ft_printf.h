/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:57:27 by jbarette          #+#    #+#             */
/*   Updated: 2021/03/19 12:50:20 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

extern int		g_i;

int		ft_printf(const char *str, ...);
int		ft_treatment(const char *str, va_list args);
int		ft_putchar(char c);
int		ft_is_in_type_list(char type);
int		ft_is_in_flag_list(char flag);
int		ft_parse_type(char type, va_list args, int width);
int		ft_parse_type_number(char type, va_list args, int width);
int		ft_treat_string_number(const char *str, int width);
int		ft_treat_int_number(int nbr, int width);
int		ft_treat_character_number(char c, int width);
int		ft_parse_type_prec(char type, va_list args, int width);
int		ft_treat_string(const char *str, int width);
int		ft_treat_int(int nbr, int width);
int		ft_treat_character(char c, int width);
int		ft_add_space(int width);
int		ft_take_width(const char *str, int i);
int		ft_parse_flag(const char *str, va_list args);
int		ft_treatment_percent(const char *str, va_list args);
int		ft_treatment_star(const char *str, va_list args, int width);
int		ft_treatment_dot_space(const char *str, va_list args, int width);
int		ft_treatment_dot(const char *str, va_list args, int width);
int		ft_parse_type_dot(char type, va_list args, int width);
int		ft_treat_string_dot(const char *str, int width);
int		ft_parse_type_dot_space(char type, va_list args, int width);
int		ft_parse_type_dot_space_prec(char type, va_list args,
									int width_arg, int width);
int		ft_treat_string_dot_space(const char *str, int width);
int		ft_treat_string_dot_space_prec(const char *str,
										int width, int width_prec);
int		ft_treatment_dot_space_prec(const char *str, va_list args,
										int width_prec);
int		ft_putnbr(int n);
int		ft_parse_star(const char *str, va_list args);
int		ft_parse_dot(const char *str, va_list args);
int		ft_parse_minus(const char *str, va_list args);
int		ft_parse_type_minus_space_prec(char type, va_list args,
									int width, int width_prec);
int		ft_treat_string_minus_space_prec(const char *str,
										int width, int width_prec);
int		ft_treat_int_dot(int nbr, int width);
int		ft_treat_int_minus_space_prec(int nbr, int width, int width_prec);
int		ft_treat_int_dot_space_prec(int nbr, int width, int width_prec);
int		ft_treatment_digit(const char *str, va_list args);
int		ft_isdigit_minus(const char *str, va_list args);
int		ft_treat_int_prec(long int nbr, int width);
int		ft_treatment_dot_no_prec(const char *str, va_list args);
int		ft_parse_type_dot_no_prec(char type, va_list args);
int		ft_treat_int_dot_no_prec(int nbr);
int		ft_treat_int_dot_space(int nbr, int width);
int		ft_treat_uint_dot(int width);
int		ft_treat_uint(unsigned int nbr, int width);
int		ft_treat_u_dot(unsigned int nbr, int width);
int		ft_treat_u_minus_space_prec(unsigned int nbr, int width,
										int width_prec);
int		ft_treat_u_dot_space_prec(unsigned int nbr, int width, int width_prec);
char	*ft_u_itoa(unsigned int n);
int		ft_treat_u_number(unsigned int nbr, int width);
int		ft_treat_u_prec(unsigned int nbr, int width);
int		ft_treat_umax_dot(int width);
int		ft_treat_u_dot_space(unsigned int nbr, int width);
int		ft_treat_pointer(unsigned long long pointer, int width);
char	*convert_base(unsigned long long nbr, int base);
int		ft_treat_pointer_number(unsigned long long nbr, int width);
int		ft_treat_hexa(unsigned int nbr, int lower, int width);
int		ft_treat_hexa_dot(unsigned int nbr, int lower, int width);
int		ft_treat_hexa_minus_space_prec(unsigned int nbr, int lower,
										int width, int width_prec);
int		ft_treat_hexa_dot_space_prec(unsigned int nbr, int lower,
									int width, int width_prec);
int		ft_treat_hexa_prec(unsigned int nbr, int lower,
							int width);
int		ft_treat_percent_number(int width);
int		ft_treat_percent_minus_space(int width);
int		ft_treat_percent_dot_space(int width);
int		ft_treat_pointer_dot_no_prec(unsigned long long nbr);
int		ft_treat_character_dot_prec(char c);
int		ft_parse_type_number_zero(char type, va_list args, int width);
int		ft_treat_int_number_zero(int nbr, int width);
int		ft_treat_u_number_zero(unsigned int nbr, int width);
int		ft_treat_hexa_number(unsigned int nbr, int lower, int width);
int		ft_treat_hexa_number_zero(unsigned int nbr, int lower, int width);
int		ft_treat_x_dot_space(unsigned long long nbr, int lower, int width);
int		ft_treat_number_space_prec(int width);
int		ft_treat_u_dot_no_prec(int nbr);
int		ft_treat_hexa_dot_no_prec(unsigned long long nbr, int lower);
int		ft_treat_pointer_dot_space(unsigned long long nbr, int width);
int		ft_treat_character_dot_space(char c, int width);
int		ft_treat_pointer_minus_space_prec(unsigned long long nbr,
										int width, int width_prec);
int		ft_treat_int_zero(int nbr, int width);
int		ft_parse_type_zero(char type, va_list args, int width);
int		ft_parse_zero(const char *str, va_list args);
int		ft_treat_int_zero_space_prec(int nbr, int width, int width_prec);
int		ft_treat_hexa_zero(unsigned int nbr, int lower, int width);
int		ft_treat_u_zero(unsigned int nbr, int width);
int		ft_treat_u_zero_space_prec(unsigned int nbr, int width,
									int width_prec);
int		ft_treat_hexa_zero_space_prec(unsigned int nbr, int lower,
									int width, int width_prec);
int		ft_treat_string_dot_no_prec(va_list args);
int		ft_treatment_digit_flag(const char *str, va_list args,
								int width, char *widthc);
int		ft_treatment_digit_star_flag(const char *str, va_list args);
int		ft_treatment_digit_dot_flag(const char *str, va_list args, int width);
int		ft_treatment_digit_dot_star_flag(const char *str,
										va_list args, int width);
int		ft_treat_pointer_dot_space_utils(unsigned long long nbr,
										char *nbrc);
int		ft_treat_hexa_dot_no_prec_utils1(int width, int width_prec,
										char *hexa);
int		ft_treat_hexa_dot_no_prec_utils2(int width, int diff,
										char *hexa);
int		ft_treat_hexa_dot_no_prec_utils3(int width,
										char *hexa);
int		ft_treat_hexa_dot_no_prec_utils4(unsigned long long nbr,
										char *nbrc, int lower);
int		ft_treat_hexa_dot_no_prec_utils5(int width);
int		ft_treat_hexa_zero_space_prec_utils2(int width_prec,
											int width, char *hexa);
int		ft_treat_hexa_zero_space_prec_utils3(int width, int width_prec,
											char *hexa);
int		ft_treat_hexa_zero_space_prec_utils1(int width_prec,
										char *hexa);
int		ft_treat_hexa_zero_space_prec_utils4(int width, int width_prec,
											char *hexa);
int		ft_treat_u_zero_space_prec_utils1(int width_prec, int width,
										char *d_i);
int		ft_treat_u_zero_space_prec_utils2(int width, int width_prec,
										char *d_i);
int		ft_treat_u_zero_space_prec_utils3(int width_prec,
										char *d_i);
int		ft_treat_u_dot_space_prec_utils1(unsigned int nbr, int width,
									int width_prec, char *nbrc);
int		ft_treat_u_dot_space_prec_utils2(int width, char *nbrc, int diff);
int		ft_treat_int_zero_space_prec1(int width_prec, int width,
									int x, char *d_i);
int		ft_treat_int_zero_space_prec2(int width, int width_prec,
									char *d_i, int y);
int		ft_treat_int_zero_space_prec3(int x, int width_prec,
									char *d_i, int width);
int		ft_treat_int_zero_space_prec4(int width, int width_prec,
									int y);
int		ft_treat_int_dot_space_prec1(int width, int width_prec,
									int x, char *d_i);
int		ft_treat_int_dot_space_prec2(int width, char *d_i, int diff, int x);
int		ft_treat_int_dot1(int width, char *d_i);
int		ft_treat_int_zero1(int width, int x, char *d_i);
int		ft_treat_hexa_minus_space_prec1(int width_prec, unsigned int nbr,
										char *hexa, int lower);
int		ft_treat_u_minus_space_prec1(int width_prec, int count_nbr);
int		ft_treat_int_minus_space_prec1(int width_prec, char *d_i,
										int width, int x);
int		ft_treat_string_minus_space_prec1(const char *str, int x);
int		ft_treat_string_minus_space_prec2(const char *str, int x);
int		ft_treat_string_minus_space_prec3(int diff, int width, const char *str,
										int width_prec);
int		ft_treat_string_minus_space_prec4(int diff, int x, const char *str);
int		ft_treat_string_minus_space_prec5(int width, int char_count);
int		convert_base1(unsigned long long nbr, int base);
int		ft_parse_type_u(va_list args, int width, int width_prec);
int		ft_parse_type_int(va_list args, int width, int width_prec);
int		ft_parse_type_x(va_list args, int width, int width_prec);
int		ft_parse_type_xcase(va_list args, int width, int width_prec);
int		ft_parse_flag2(const char *str, va_list args);
int		ft_parse_flag_zero_star(const char *str, va_list args);
int		ft_parse_flag_zero_dot(const char *str, va_list args);
int		ft_parse_minus2(const char *str, va_list args);
int		ft_parse_minus_dot_star(const char *str, va_list args);
int		ft_parse_minus_dot(const char *str, va_list args);
int		ft_isdigit_and_minus(const char *str, va_list args, int width);
int		ft_isdigit_star(const char *str, va_list args, int width);
int		ft_isdigit_flag_minus(const char *str, va_list args);
int		ft_isdigit_minus_space_prec(const char *str, va_list args,
									int	width);
int		ft_parse_isdigit_minus2(const char *str);
int		ft_parse_star2(const char *str, va_list args);
int		ft_parse_isdigit_star2(const char *str, va_list args);
int		ft_parse_zero2(const char *str, va_list args);
int		ft_parse_zero_isdigit(const char *str, va_list args);
#endif
