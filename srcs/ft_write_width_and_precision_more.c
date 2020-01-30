/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_width_and_precision_more.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:42:15 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 14:12:48 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_width_and_precision_string(t_flags *flags, int *res)
{
	char	*str;

	if (flags->specifier == 's')
	{
		if (flags->precision < 0)
			flags->precision = flags->length_output;
		str = flags->output;
		if (!(str = ft_substr(str, 0, flags->precision)))
			return (-1);
		flags->length_output = ft_strlen(str);
		if (!flags->dash && flags->width > 0)
			ft_isalign(flags->width - flags->length_output, res);
		ft_putstr_fd(str, 1);
		*res += flags->length_output;
		free(str);
	}
	return (0);
}

int		ft_print_width_and_precision_negative_more(t_flags *flags, int *res)
{
	int	output;

	if (flags->precision >= flags->width)
	{
		output = ft_int_negative_to_positive(flags);
		ft_iszero(flags->precision - flags->length_output + 1, res);
		ft_putnbr_unsigned_fd(output, 1);
		*res += flags->length_output;
		return (TRUE);
	}
	else if (flags->precision < flags->width)
	{
		!flags->dash ? ft_isalign(flags->width - flags->precision - 1, res) : 0;
		output = ft_int_negative_to_positive(flags);
		ft_iszero(flags->precision - flags->length_output + 1, res);
		ft_putnbr_unsigned_fd(output, 1);
		flags->dash ? ft_isalign(flags->width - flags->precision - 1, res) : 0;
		*res += flags->length_output;
		return (TRUE);
	}
	return (FALSE);
}
