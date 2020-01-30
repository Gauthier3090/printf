/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:03:18 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/13 18:34:32 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_width(const char *format, va_list list,
		int *index, t_flags *flags)
{
	while (ft_isdigit(format[*index]) || format[*index] == '*')
	{
		if (format[*index] == '*')
		{
			flags->width = va_arg(list, int);
			(*index)++;
		}
		if (ft_isdigit(format[*index]))
		{
			while (ft_isdigit(format[*index]))
			{
				flags->width = flags->width * 10 + (format[*index] - '0');
				(*index)++;
			}
		}
	}
}
