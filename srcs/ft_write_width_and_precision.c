/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_width_and_precision.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:23:10 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 14:44:58 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_precision_negative(t_flags *flags, int *res)
{
	int	output;

	if (flags->precision < 0)
	{
		flags->precision *= -1;
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->zero = FALSE;
		}
		output = ft_int_negative_to_positive(flags);
		if (flags->zero)
			ft_iszero(flags->width - flags->length_output, res);
		ft_putnbr_unsigned_fd(output, 1);
		if (!flags->zero)
			ft_isalign(flags->width - flags->length_output, res);
		*res += flags->length_output;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_print_width_and_precision_negative(t_flags *flags, int *res)
{
	int	output;

	if (ft_print_precision_negative(flags, res))
		return ;
	if (flags->width < 0)
	{
		flags->dash = TRUE;
		flags->width *= -1;
	}
	if (flags->precision < flags->length_output)
	{
		!flags->dash ? ft_isalign(flags->width - flags->length_output, res) : 0;
		output = ft_int_negative_to_positive(flags);
		ft_putnbr_unsigned_fd(output, 1);
		flags->dash ? ft_isalign(flags->width - flags->length_output, res) : 0;
	}
	else if (ft_print_width_and_precision_negative_more(flags, res))
		return ;
	*res += flags->length_output;
}

int		ft_print_width_and_precision_special_case(t_flags *flags, int *res)
{
	if (flags->precision == 0 && flags->output == 0 && flags->specifier != '%')
	{
		flags->width < 0 ? flags->width *= -1 : 0;
		ft_isalign(flags->width, res);
		return (TRUE);
	}
	if ((int)flags->output < 0 &&
		(flags->specifier == 'd' || flags->specifier == 'i'))
	{
		ft_print_width_and_precision_negative(flags, res);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_print_width_and_precision_dash(t_flags *flags, int *res)
{
	if (flags->width < 0)
		flags->width *= -1;
	if (flags->specifier == 's')
		ft_isalign(flags->width - flags->length_output, res);
	else
	{
		if (ft_print_width_and_precision_special_case(flags, res))
			return ;
		else if (flags->precision < flags->length_output
		|| flags->specifier == '%')
			ft_isalign(flags->width - flags->length_output, res);
		else if (flags->precision < flags->width)
			ft_isalign(flags->width - flags->precision, res);
	}
}

void	ft_print_width_and_precision(t_flags *flags, int *res)
{
	if (flags->specifier != 's')
	{
		if (ft_print_width_and_precision_special_case(flags, res))
			return ;
		else if ((flags->precision < flags->length_output
		|| flags->specifier == '%') && !flags->dash)
		{
			((flags->zero && flags->precision < 0) ||
			(flags->specifier == '%' && flags->zero))
			? ft_iszero(flags->width - flags->length_output, res)
			: ft_isalign(flags->width - flags->length_output, res);
		}
		else if (flags->precision >= flags->width && flags->specifier != '%')
			ft_iszero(flags->precision - flags->length_output, res);
		else if (flags->precision < flags->width && flags->specifier != '%')
		{
			!flags->dash ? ft_isalign(flags->width - flags->precision, res) : 0;
			ft_iszero(flags->precision - flags->length_output, res);
		}
		ft_write_output(flags, res);
	}
	if (ft_print_width_and_precision_string(flags, res) == -1)
		return ;
	if (flags->dash || flags->width < 0)
		ft_print_width_and_precision_dash(flags, res);
}
