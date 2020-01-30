/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_formatted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:15:36 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/14 13:16:16 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_formatted(t_flags *flags, int *res)
{
	if (flags->width && flags->point)
		ft_print_width_and_precision(flags, res);
	else if (flags->zero && !flags->dash && flags->width > 0)
		ft_print_flag_zero(flags, res);
	else if (flags->point && flags->specifier != 'c' && flags->specifier != '%')
		ft_print_precision(flags, res);
	else if (flags->width || flags->dash)
		ft_print_width(flags, res);
	else
		ft_write_output(flags, res);
}
