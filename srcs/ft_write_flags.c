/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:38:03 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 13:39:53 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_width(t_flags *flags, int *res)
{
	if (flags->width > 0 && !flags->dash)
		ft_write_width(flags, res);
	ft_write_output(flags, res);
	if (flags->width < 0 || flags->dash)
		ft_write_width(flags, res);
}

void	ft_print_flag_zero(t_flags *flags, int *res)
{
	int	output;

	if ((int)flags->output < 0 &&
		(flags->specifier == 'd' || flags->specifier == 'i'))
	{
		output = ft_int_negative_to_positive(flags);
		ft_iszero(flags->width - flags->length_output, res);
		ft_putnbr_unsigned_fd(output, 1);
		*res += flags->length_output;
	}
	else
	{
		ft_iszero(flags->width - flags->length_output, res);
		ft_write_output(flags, res);
	}
}

void	ft_print_precision_string(t_flags *flags, int *res)
{
	char	*str;

	if (flags->precision < 0)
	{
		ft_write_output(flags, res);
		return ;
	}
	str = flags->output;
	if (!(str = ft_substr(str, 0, flags->precision)))
		return ;
	flags->length_output = ft_strlen(str);
	ft_putstr_fd(str, 1);
	*res += flags->length_output;
	free(str);
}

void	ft_print_precision(t_flags *flags, int *res)
{
	int	output;

	if (flags->specifier == 's')
		ft_print_precision_string(flags, res);
	else
	{
		if ((int)flags->output < 0 &&
			(flags->specifier == 'd' || flags->specifier == 'i'))
		{
			output = ft_int_negative_to_positive(flags);
			ft_iszero(flags->precision - flags->length_output + 1, res);
			ft_putnbr_unsigned_fd(output, 1);
			*res += flags->length_output;
			return ;
		}
		else if ((int)flags->output == 0 && flags->precision >= 0)
		{
			ft_iszero(flags->precision, res);
			return ;
		}
		else
			ft_iszero(flags->precision - flags->length_output, res);
		ft_write_output(flags, res);
	}
}
