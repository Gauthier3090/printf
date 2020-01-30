/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:13:23 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/13 15:24:29 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_flags(const char *format, int *index, t_flags *flags)
{
	while (format[*index] == '0' || format[*index] == '-')
	{
		format[*index] == '0' ? flags->zero = TRUE : 0;
		format[*index] == '-' ? flags->dash = TRUE : 0;
		(*index)++;
	}
}
