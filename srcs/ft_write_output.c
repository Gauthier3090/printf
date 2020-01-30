/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:45:18 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/15 13:47:35 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_write_output(t_flags *flags, int *res)
{
	if (flags->specifier == '%')
		ft_putchar_fd('%', 1);
	if (flags->specifier == 'c')
		ft_putchar_fd((char)flags->output, 1);
	if (flags->specifier == 's')
		ft_putstr_fd(flags->output, 1);
	if (flags->specifier == 'd')
		ft_putnbr_fd((int)flags->output, 1);
	if (flags->specifier == 'i')
		ft_putnbr_fd((int)flags->output, 1);
	if (flags->specifier == 'u')
		ft_putnbr_unsigned_fd((unsigned int)flags->output, 1);
	if (flags->specifier == 'x')
		ft_puthexa(flags, (unsigned int)flags->output);
	if (flags->specifier == 'X')
		ft_puthexa(flags, (unsigned int)flags->output);
	if (flags->specifier == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthexa(flags, (unsigned long)flags->output);
	}
	*res += flags->length_output;
}
