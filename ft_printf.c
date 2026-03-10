/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:39:00 by varandri          #+#    #+#             */
/*   Updated: 2026/03/10 13:16:10 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c, va_list arg)
{
	int		count;

	count = 0;
	if (c == 's')
		count = ft_print_str(va_arg(arg, char *));
	else if (c == 'c')
		count = ft_print_chr(va_arg(arg, int));
	else if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(arg, int));
	else if (c == 'x')
		count = ft_print_hex(va_arg(arg, unsigned int), NULL);
	else if (c == 'X')
		count = ft_print_hex(va_arg(arg, unsigned int), ft_str_toupper);
	else if (c == 'p')
		count = ft_print_ptr(va_arg(arg, unsigned long));
	else if (c == 'u')
		count = ft_print_uint(va_arg(arg, unsigned int));
	else if (c == '%')
		count = ft_print_chr(c);
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
		if (c[i] != '%')
			count += ft_print_chr(c[i]);
		if (c[i] == '%')
		{
			i ++;
			count += check_flag(c[i], args);
		}
		i ++;
	}
	va_end(args);
	return (count);
}
