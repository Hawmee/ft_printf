/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:40:19 by varandri          #+#    #+#             */
/*   Updated: 2026/03/10 11:47:41 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

char	*ft_str_toupper(char *s);
int		ft_printf(const char *c, ...);
int		ft_print_str(char *s);
int		ft_print_chr(char c);
int		ft_print_int(int n);
int		ft_print_hex(unsigned int n, char *(*f)(char *));
int		ft_print_ptr(unsigned long int ptr);
int		ft_print_uint(unsigned int n);

#endif