/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:03:12 by varandri          #+#    #+#             */
/*   Updated: 2026/03/10 12:03:10 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_toupper(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
