/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:56:02 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/14 13:55:36 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	length_uitoa(unsigned int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char		*ft_uitoa(unsigned int n)
{
	char			*word;
	unsigned int	i;

	i = length_uitoa(n);
	if (!(word = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
	{
		word[0] = '0';
		return (word);
	}
	while (n > 0)
	{
		word[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (word);
}

void		ft_putnbr_unsigned_fd(unsigned int nb, int fd)
{
	if (fd < 0 || fd > OPEN_MAX)
		return ;
	if (nb > 9)
	{
		ft_putnbr_unsigned_fd(nb / 10, fd);
		ft_putnbr_unsigned_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void		ft_puthexa(t_flags *flags, unsigned long nb)
{
	if (nb > 15)
	{
		ft_puthexa(flags, nb / 16);
		ft_puthexa(flags, nb % 16);
	}
	else if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		if (flags->specifier == 'x' || flags->specifier == 'p')
		{
			nb == 10 ? ft_putchar_fd('a', 1) : 0;
			nb == 11 ? ft_putchar_fd('b', 1) : 0;
			nb == 12 ? ft_putchar_fd('c', 1) : 0;
			nb == 13 ? ft_putchar_fd('d', 1) : 0;
			nb == 14 ? ft_putchar_fd('e', 1) : 0;
			nb == 15 ? ft_putchar_fd('f', 1) : 0;
		}
		nb == 10 && flags->specifier == 'X' ? ft_putchar_fd('A', 1) : 0;
		nb == 11 && flags->specifier == 'X' ? ft_putchar_fd('B', 1) : 0;
		nb == 12 && flags->specifier == 'X' ? ft_putchar_fd('C', 1) : 0;
		nb == 13 && flags->specifier == 'X' ? ft_putchar_fd('D', 1) : 0;
		nb == 14 && flags->specifier == 'X' ? ft_putchar_fd('E', 1) : 0;
		nb == 15 && flags->specifier == 'X' ? ft_putchar_fd('F', 1) : 0;
	}
}

int			ft_lengthhexa(unsigned long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		size++;
	}
	return (size);
}
