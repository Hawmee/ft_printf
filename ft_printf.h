/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:40:19 by varandri          #+#    #+#             */
/*   Updated: 2026/02/15 18:38:57 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_toupper(char *s);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *c, ...) __attribute__((format(printf, 1, 2)));
int		ft_print_str(char *s);
int		ft_print_chr(char c);
int		ft_print_int(int n);
int		ft_print_hex(unsigned int n, char *(*f)(char *));
int		ft_print_ptr(unsigned long int ptr);
int		ft_print_uint(unsigned int n);

#endif