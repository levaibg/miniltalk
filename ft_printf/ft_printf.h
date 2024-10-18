/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:22:08 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/17 20:43:30 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putnbr_base(unsigned long long nbr, char *base);
int		ft_printe(char c);
int		print_unsigned(unsigned int nb);
int		ft_printf(const char *input, ...);
int		ft_string(char *str);
int		print_ptr(char *ptr, char *base);
int		ft_printnb(int n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
