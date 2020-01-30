/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:29:53 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 14:18:55 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_output_number(t_flags *flags)
{
	char	*nb;

	if (flags->specifier == 'd')
	{
		if (!(nb = ft_itoa((int)flags->output)))
			return (-1);
		flags->length_output = ft_strlen(nb);
		free(nb);
	}
	if (flags->specifier == 'i')
	{
		if (!(nb = ft_itoa((int)flags->output)))
			return (-1);
		flags->length_output = ft_strlen(nb);
		free(nb);
	}
	if (flags->specifier == 'u')
	{
		if (!(nb = ft_uitoa((unsigned int)flags->output)))
			return (-1);
		flags->length_output = ft_strlen(nb);
		free(nb);
	}
	return (0);
}

int	ft_handle_output(va_list list, t_flags *flags)
{
	if (flags->specifier != '%')
		flags->output = va_arg(list, void *);
	if (ft_handle_output_number(flags) == -1)
		return (-1);
	if (!flags->output && flags->specifier == 's')
		flags->output = "(null)";
	if (flags->specifier == '%')
		flags->length_output = 1;
	if (flags->specifier == 'c')
		flags->length_output = 1;
	if (flags->specifier == 's')
		flags->length_output = ft_strlen(flags->output);
	if (flags->specifier == 'x')
		flags->length_output = ft_lengthhexa((unsigned int)flags->output);
	if (flags->specifier == 'X')
		flags->length_output = ft_lengthhexa((unsigned int)flags->output);
	if (flags->specifier == 'p')
		flags->length_output = ft_lengthhexa((unsigned long)flags->output) + 2;
	return (0);
}
