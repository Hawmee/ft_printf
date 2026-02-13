/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:09:21 by varandri          #+#    #+#             */
/*   Updated: 2026/02/13 18:17:53 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_int_len(unsigned int n)
{
	size_t	i;

	i = 0;
	if (!n)
		i ++;
	while (n)
	{
		i ++;
		n /= 10;
	}
	return (i);
}

static void	ft_convert(char *str, unsigned int n, size_t n_len)
{
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[n_len - 1] = n % 10 + '0';
		n /= 10;
		n_len --;
	}
}

int	ft_print_uint(unsigned int n)
{
	unsigned int	nbr;
	size_t			n_len;
	char			*str;

	nbr = n;
	n_len = ft_int_len(nbr);
	str = ft_calloc((n_len + 1), sizeof(char));
	if (!str)
		return (-1);
	ft_convert(str, nbr, n_len);
	write(1, str, n_len);
	free(str);
	return (n_len);
}
