/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:52 by gpladet           #+#    #+#             */
/*   Updated: 2019/11/23 23:13:39 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length_itoa(int n)
{
	unsigned int	length;
	unsigned int	nb;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = n * (-1);
		length++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char				*ft_itoa(int n)
{
	char			*word;
	unsigned int	i;
	unsigned int	nb;

	i = length_itoa(n);
	if (!(word = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
	{
		word[0] = '0';
		return (word);
	}
	if (n < 0)
	{
		word[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	while (nb > 0)
	{
		word[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (word);
}
