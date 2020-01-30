/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:52:22 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/14 13:45:04 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		res;
	int		index;
	va_list	list;

	res = 0;
	index = -1;
	va_start(list, format);
	while (format[++index])
	{
		if (format[index] == '%')
		{
			index++;
			ft_handle_conversion(format, list, &index, &res);
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			res++;
		}
	}
	va_end(list);
	return (res);
}
