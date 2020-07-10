/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_0_or_32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:59:03 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/10 17:57:34 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int				count_num(int num_copy, int *counter)
{
	int num_i;

	num_i = 0;
	if (counter[5] && !counter[6])
		return (0);
	if (num_copy <= 0)
		num_i++;
	if (num_copy != 0 && (counter[2] || counter[5]))
	{
		while (num_copy != 0)
		{
			num_i++;
			num_copy /= 10;
		}
	}
	return (num_i);
}

static int				num_min(int *counter, int num)
{
	while (counter[2] > count_num(num, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
	return (num);
}

static int				put_id(int *counter, int num)
{
	int num_copy;

	num_copy = num;
	if (num == -2147483648)
	{
		counter[8] = 1;
		ft_putchar_fd('-', 1, counter);
	}
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_num(num_copy, counter) || counter[6] > counter[2])
	{
		if (num < 0)
		{
			if (!counter[8])
				ft_putchar_fd('-', 1, counter);
			num *= -1;
			counter[6]++;
		}
		while (counter[6] > count_num(num_copy, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	if (num == -2147483648)
		return (num_min(counter, num));
	while (counter[2] > count_num(num_copy, counter) && !counter[7])
	{
		if (num < 0 && ((counter[4] && !counter[5]) || counter[6] + 1 >= counter[2]))
		{
			ft_putchar_fd('-', 1, counter);
			ft_putchar_fd('0', 1, counter);
			num *= -1;
		}
		else if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
	return (num);
}

static int				count_xx(unsigned int num_copy, int *counter)
{
	int num_i;

	num_i = 0;
	if (counter[5] && !counter[6])
		return (0);
	if (num_copy <= 0)
		num_i++;
	if (num_copy != 0 && (counter[2] || counter[5]))
	{
		while (num_copy != 0)
		{
			num_i++;
			num_copy /= 16;
		}
	}
	return (num_i);
}

static unsigned int		put_xx(int *counter, unsigned int num)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_xx(num, counter))
	{
		while (counter[6] > count_xx(num, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_xx(num, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
	if (num == 0 && !(counter[5] && !counter[6]))
		ft_putchar_fd('0', 1, counter);
	return (num);
}

int						put_0_or_32(const char *format, int *counter,
unsigned int num, int num_int)
{
	if (format[counter[0] + 1] == 'd' || format[counter[0] + 1] == 'i')
		return (put_id(counter, num_int));
	if (format[counter[0] + 1] == 'X' || format[counter[0] + 1] == 'x')
		return(put_xx(counter, num));
	return (0);
}
