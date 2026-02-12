/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:06:26 by varandri          #+#    #+#             */
/*   Updated: 2026/02/12 15:59:30 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_hex_len(unsigned int n)
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

static	void	ft_convert(char *res, unsigned int n)
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
			res[n_hex_len - 1] = 'a' + (n % 10);
		if ((n % 16) <= 9)
			res[n_hex_len - 1] = '0' + (n % 16);
		n /= 16;
		n_hex_len--;
	}
}

int	ft_print_hex(unsigned int	n, char *(*f)(char *))
{
	char			*res;
	int				count;
	
	res  = (char *)ft_calloc((ft_hex_len(n) + 1), sizeof(char));
	if (!res)
		return (0);
	ft_convert(res, n);
	if (f)
		count = ft_print_str(f(res));
	else
		count = ft_print_str(res);
	free(res);
	return (count);
}