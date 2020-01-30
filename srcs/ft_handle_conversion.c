/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:09:02 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/20 14:18:30 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_conversion(const char *format, va_list list,
		int *index, int *res)
{
	t_flags *flags;

	flags = ft_calloc(1, sizeof(t_flags));
	ft_handle_flags(format, index, flags);
	ft_handle_width(format, list, index, flags);
	ft_handle_precision(format, list, index, flags);
	ft_handle_specifier(format, index, flags);
	if (ft_handle_output(list, flags) == 0)
		ft_handle_formatted(flags, res);
	free(flags);
}
