/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:53:46 by varandri          #+#    #+#             */
/*   Updated: 2026/02/08 16:29:02 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

int main (void)
{
	char *test = NULL;
	ft_printf("helllo %s %s", test, "hell");
	return (0);
}