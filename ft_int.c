/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:55:07 by varandri          #+#    #+#             */
/*   Updated: 2026/02/08 16:25:15 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_int_len(int n)
{
	size_t	i;

	i = 0;
	if (!n)
		i ++;
	if (n < 0)
	{
		n = -n;
		i ++;
	}
	while (n)
	{
		i ++;
		n /= 10;
	}
	return (i);
}

static void	ft_convert(char *str, long n, size_t n_len)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[n_len - 1] = n % 10 + '0';
		n /= 10;
		n_len --;
	}
}

int	ft_int(int n)
{
	long	nbr;
	size_t	n_len;
	char	*str;

	nbr = n;
	n_len = ft_int_len(nbr);
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (-1);
	str[n_len] = '\0';
	ft_convert(str, nbr, n_len);
	write(1, str, n_len);
	free(str);
	return (n_len);
}
