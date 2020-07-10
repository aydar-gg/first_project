/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:50:27 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/10 10:16:14 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_printf_part7(const char *format, va_list ap,
int *counter)
{
	int num_int;
	int num_int_copy;

	if (format[counter[1]] == '%' && (format[counter[0] + 1] == 'd'
	|| format[counter[0] + 1] == 'i'))
	{
		num_int = va_arg(ap, int);
		num_int_copy = num_int;
		num_int = put_0_or_32(format, counter, 1, num_int_copy);
		if (counter[5] && !counter[6])
		{
			put_dif(counter, num_int_copy);
			counter[0]++;
			return (1);
		}
		ft_putnbr_fd(num_int, 1, counter);
		put_dif(counter, num_int_copy);
		counter[0]++;
		return (1);
	}
	return (0);
}

static int		ft_printf_part6(const char *format, va_list ap,
int *counter)
{
	unsigned int num;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'x')
	{
		num = va_arg(ap, unsigned int);
		put_0_or_32(format, counter, num, 1);
		if (counter[5] && !counter[6])
		{
			put_dif(counter, num);
			counter[0]++;
			return (1);
		}
		x_littel(num, counter);
		put_dif_xx(counter, num);
		counter[0]++;
		return (1);
	}
	else if (format[counter[1]] == '%' && format[counter[0] + 1] == 'X')
	{
		num = va_arg(ap, unsigned int);
		put_0_or_32(format, counter, num, 1);
		if (counter[5] && !counter[6])
		{
			put_dif(counter, num);
			counter[0]++;
			return (1);
		}
		x_big(num, counter);
		put_dif_xx(counter, num);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part7(format, ap, counter));
}

static int		ft_printf_part5(const char *format, va_list ap,
int *counter)
{
	size_t num_long;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'p')
	{
		num_long = va_arg(ap, size_t);
		put_0_or_32_p(num_long, counter);
		ft_putstr_fd("0x", 1, counter);
		if (num_long == 0)
			ft_putchar_fd('0', 1, counter);
		p_function(num_long, counter);
		put_dif_p(num_long, counter);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part6(format, ap, counter));
}

static int		ft_printf_part4(const char *format, va_list ap,
int *counter)
{
	unsigned char c;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (counter[2] && !counter[7])
			while (counter[2] - 1)
			{
				if (counter[4])
					ft_putchar_fd('0', 1, counter);
				else
					ft_putchar_fd(' ', 1, counter);
				counter[2]--;
			}
		ft_putchar_fd(c, 1, counter);
		if (counter[7] && counter[2])
			while (counter[2] - 1)
			{
				ft_putchar_fd(' ', 1, counter);
				counter[2]--;
			}
		counter[0]++;
		return (1);
	}
	return (ft_printf_part5(format, ap, counter));
}

static int		ft_printf_part3(const char *format, va_list ap,
int *counter)
{
	char *str;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 's')
	{
		str = va_arg(ap, char*);
		put_0_or_32_s(str, counter);
		return (1);
	}
	return (ft_printf_part4(format, ap, counter));
}

void			ft_printf_part2(const char *format, va_list ap,
int *counter)
{
	int num_int;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'u')
	{
		num_int = va_arg(ap, int);
		u_function(num_int, counter);
		counter[0]++;
	}
	else if (format[counter[1]] == '%' && format[counter[0] + 1] == '%')
	{
		if (counter[2] && !counter[7])
			while (counter[2] - 1)
			{
				if (counter[4])
					ft_putchar_fd('0', 1, counter);
				else
					ft_putchar_fd(' ', 1, counter);
				counter[2]--;
			}
		ft_putchar_fd('%', 1, counter);
		if (counter[7] && counter[2])
			while (counter[2] - 1)
			{
				ft_putchar_fd(' ', 1, counter);
				counter[2]--;
			}
		counter[0]++;
	}
	else if (ft_isascii((unsigned char)format[counter[0]]) &&
!ft_printf_part3(format, ap, counter))
		ft_putchar_fd(format[counter[0]], 1, counter);
}
