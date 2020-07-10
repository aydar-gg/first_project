/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:34:07 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/10 16:16:42 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_flags_part2(const char *format, int *counter, va_list ap,
int alpha)
{
	if (format[counter[0] + 1] == '0')
	{
		alpha = 1;
		counter[4] = 1;
		counter[0]++;
	}
	if (ft_isdigit(format[counter[0] + 1] - '0') ||
format[counter[0] + 1] == '*')
	{
		alpha = 1;
		if (format[counter[0] + 1] == '*')
		{
			counter[2] = va_arg(ap, int);
			if (counter[2] < 0)
			{
				counter[7] = 1;
				counter[2] *= -1;
			}
			counter[0]++;
		}
		else
		{
			counter[2] = ft_atoi(((char*)format + counter[0] + 1));
			while (ft_isdigit(format[counter[0] + 1] - '0'))
				counter[0]++;
		}
	}
	if (format[counter[0] + 1] == '.')
	{
		alpha = 1;
		counter[5] = 1;
		counter[0]++;
		if (format[counter[0] + 1] == '*')
		{
			counter[6] = va_arg(ap, int);
			counter[0]++;
		}
		else
		{
			counter[6] = ft_atoi(((char*)format + counter[0] + 1));
			while (ft_isdigit(format[counter[0] + 1] - '0'))
				counter[0]++;
		}
	}
	if (format[counter[0] + 1] == ' ')
	{
		ft_putchar_fd(' ', 1, counter);
		alpha = 0;
	}
	return (alpha);
}

static void		check_flags(const char *format, int *counter, va_list ap)
{
	int alpha;

	counter[1] = counter[0];
	counter[4] = 0;
	counter[5] = 0;
	counter[7] = 0;
	if (format[counter[1]] == '%')
	{
		while (1)
		{
			alpha = 0;
			if (format[counter[0] + 1] == '-')
			{
				counter[0]++;
				counter[7] = 1;
				alpha = 1;
			}
			alpha = check_flags_part2(format, counter, ap, alpha);
			if (ft_isalpha(format[counter[0] + 1]) ||
format[counter[0] + 1] == '%')
				break ;
			if (!alpha)
				counter[0]++;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			*counter;

	if (!(counter = (int*)malloc(9 * sizeof(int))))
		return (-1);
	counter[0] = 0;
	counter[3] = 0;
	va_start(ap, format);
	while (format[counter[0]] != '\0')
	{
		counter[2] = 0;
		counter[8] = 0;
		counter[6] = 0;
		check_flags(format, counter, ap);
		ft_printf_part2(format, ap, counter);
		counter[0]++;
	}
	va_end(ap);
	return (counter[3]);
}
