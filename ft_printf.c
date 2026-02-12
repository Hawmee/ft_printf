/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:39:00 by varandri          #+#    #+#             */
/*   Updated: 2026/02/12 15:59:15 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c, va_list arg)
{
	int		count;

	count = 0;
	if (c == 's')
		count = ft_print_str(va_arg(arg, char *));
	if (c == 'c')
		count = ft_print_chr(va_arg(arg, int));
	if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(arg, int));
	if (c == 'x')
		count = ft_print_hex(va_arg(arg, unsigned int), NULL);
	if (c == 'X')
		count = ft_print_hex(va_arg(arg, unsigned int), ft_toupper);
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
