/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:09 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/14 16:37:09 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_isalign(int width, int *res)
{
	if (width < 0)
		return ;
	while (width)
	{
		ft_putchar_fd(' ', 1);
		*res += 1;
		width--;
	}
}

void	ft_iszero(int width, int *res)
{
	if (width < 0)
		return ;
	while (width)
	{
		ft_putchar_fd('0', 1);
		*res += 1;
		width--;
	}
}

int		ft_int_negative_to_positive(t_flags *flags)
{
	int	output;

	ft_printf("-");
	output = (int)flags->output;
	output *= -1;
	return (output);
}

void	ft_write_width(t_flags *flags, int *res)
{
	if (flags->width < 0)
		flags->width *= -1;
	ft_isalign(flags->width - flags->length_output, res);
}
