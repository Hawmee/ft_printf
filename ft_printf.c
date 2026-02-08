/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:39:00 by varandri          #+#    #+#             */
/*   Updated: 2026/02/08 16:28:57 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c, va_list arg)
{
	int		count;

	count = 0;
	if(c == 's')
		count = ft_str(va_arg(arg, char *));
	if (c == 'c')
		count = ft_chr(va_arg(arg, int));
	return (count);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	
	if (!c)
		return (-1);
	i = 0;
	count = 0 ;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] != '%' || (c[i] == '%' && c[i + 1] == '%'))
			count += ft_chr(c[i]);
		if (c[i] == '%')
		{
			i ++;
			count += check_flag(c[i], (void *)args);
		}
		i ++;
	}
	va_end(args);
	return (count);
}
