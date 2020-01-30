/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:40:27 by gpladet           #+#    #+#             */
/*   Updated: 2019/11/23 23:14:37 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*word;
	size_t			i;

	word = (unsigned char*)b;
	i = 0;
	while (len > 0)
	{
		word[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
