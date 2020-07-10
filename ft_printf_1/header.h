/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:22:02 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/09 16:38:14 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_printf_part2(const char *format, va_list ap, int *counter);
void	x_littel(unsigned int num, int *counter);
void	x_big(unsigned int num, int *counter);
void	p_function(size_t num, int *counter);
void	u_function(int num_int, int *counter);
int		put_0_or_32(const char *format, int *counter,
unsigned int num, int num_int);
void	put_0_or_32_p(size_t num_long, int *counter);
void	put_0_or_32_s(char *str, int *counter);
void	put_dif(int *counter, int num_int);
void	put_dif_p(size_t num_long, int *counter);
void	put_dif_xx(int *counter, unsigned int num_int);
void	put_dif_s(char *str, int *counter);

int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		ft_isascii(int c);
int		ft_isalpha(int c);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd, int *counter);
void	ft_putchar_fd(unsigned char c, int fd, int *counter);
void	ft_putstr_fd(char *s, int fd, int *counter);

#endif
