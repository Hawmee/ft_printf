/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:36:09 by varandri          #+#    #+#             */
/*   Updated: 2026/02/13 18:17:48 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_hex_len(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i ++;
		n /= 16;
	}
	return (i);
}

static	void	ft_convert(char *res, unsigned long int n)
{
	size_t	n_hex_len;

	if (!n)
	{
		res[0] = '0';
		return ;
	}
	n_hex_len = ft_hex_len(n);
	while (n)
	{
		if ((n % 16) > 9)
			res[n_hex_len - 1] = 'a' + ((n % 16) - 10);
		if ((n % 16) <= 9)
			res[n_hex_len - 1] = '0' + (n % 16);
		n /= 16;
		n_hex_len--;
	}
}

static	int	ft_print_hex_ptr(unsigned long int ptr)
{
	char			*res;
	int				count;

	res = (char *)ft_calloc((ft_hex_len(ptr) + 1), sizeof(char));
	if (!res)
		return (0);
	ft_convert(res, ptr);
	count = ft_print_str(res);
	free(res);
	return (count);
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	count;

	if (!ptr)
	{
		count = ft_print_str("(nil)");
		return (count);
	}
	count = ft_print_str("0x");
	count += ft_print_hex_ptr(ptr);
	return (count);
}
