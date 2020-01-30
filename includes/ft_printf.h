/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:03:40 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 14:18:06 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_flags
{
	char		specifier;
	void		*output;
	int			dash;
	int			zero;
	int			point;
	int			length_output;
	int			width;
	int			precision;
}				t_flags;

int				ft_printf(const char *format, ...);

void			ft_handle_conversion(const char *format, va_list list,
				int *index, int *res);
void			ft_handle_flags(const char *format, int *index, t_flags *flags);
void			ft_handle_width(const char *format, va_list list,
				int *index, t_flags *flags);
void			ft_handle_precision(const char *format, va_list list,
				int *index, t_flags *flags);
void			ft_handle_specifier(const char *format,
				int *index, t_flags *flags);
int				ft_handle_output(va_list list, t_flags *flags);
void			ft_handle_formatted(t_flags *flags, int *res);

void			ft_write_output(t_flags *flags, int *res);
void			ft_write_width(t_flags *flags, int *res);

void			ft_print_width(t_flags *flags, int *res);
void			ft_print_flag_zero(t_flags *flags, int *res);
void			ft_print_precision(t_flags *flags, int *res);
void			ft_print_width_and_precision(t_flags *flags, int *res);
int				ft_print_width_and_precision_negative_more(t_flags *flags,
				int *res);
int				ft_print_width_and_precision_string(t_flags *flags, int *res);

void			ft_isalign(int width, int *res);
void			ft_iszero(int width, int *res);
int				ft_int_negative_to_positive(t_flags *flags);

char			*ft_uitoa(unsigned int n);
void			ft_putnbr_unsigned_fd(unsigned int nb, int fd);
void			ft_puthexa(t_flags *flags, unsigned long nb);
int				ft_lengthhexa(unsigned long nb);

#endif
