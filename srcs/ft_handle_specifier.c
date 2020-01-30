/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:54:30 by gpladet           #+#    #+#             */
/*   Updated: 2020/01/13 15:26:09 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_specifier(const char *format, int *index, t_flags *flags)
{
	format[*index] == '%' ? flags->specifier = '%' : 0;
	format[*index] == 'c' ? flags->specifier = 'c' : 0;
	format[*index] == 's' ? flags->specifier = 's' : 0;
	format[*index] == 'd' ? flags->specifier = 'd' : 0;
	format[*index] == 'i' ? flags->specifier = 'i' : 0;
	format[*index] == 'u' ? flags->specifier = 'u' : 0;
	format[*index] == 'x' ? flags->specifier = 'x' : 0;
	format[*index] == 'X' ? flags->specifier = 'X' : 0;
	format[*index] == 'p' ? flags->specifier = 'p' : 0;
}
