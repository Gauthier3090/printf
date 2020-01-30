/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:31:46 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/13 18:32:57 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_precision(const char *format, va_list list,
		int *index, t_flags *flags)
{
	if (format[*index] == '.')
	{
		flags->point = TRUE;
		(*index)++;
		if (format[*index] == '*')
		{
			flags->precision = va_arg(list, int);
			(*index)++;
		}
		if (ft_isdigit(format[*index]))
		{
			while (ft_isdigit(format[*index]))
			{
				flags->precision = flags->precision * 10;
				flags->precision += format[*index] - '0';
				(*index)++;
			}
		}
	}
}
