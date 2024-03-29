/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:18:29 by gpladet           #+#    #+#             */
/*   Updated: 2019/11/23 23:15:35 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*word;

	word = (char *)s;
	i = ft_strlen(word);
	while (i >= 0)
	{
		if (word[i] == c)
			return (&word[i]);
		i--;
	}
	return (0);
}
