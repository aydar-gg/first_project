/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 00:17:12 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/07 13:15:31 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_num(unsigned int num_copy, int *counter)
{
	int num_i;

	num_i = 0;
	if (counter[5] && !counter[6])
		return (0);
	if (num_copy == 0)
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

static void		u_putnbr_fd(unsigned int num, int fd, int *counter)
{
	if (num > 9)
		u_putnbr_fd(num / 10, fd, counter);
	ft_putchar_fd((num % 10) + '0', fd, counter);
}

static void		zero_32_num(unsigned int num, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_num(num, counter))
	{
		while (counter[6] > count_num(num, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_num(num, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
}

static void		zero_32_num_int(int num_int, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_num(num_int, counter))
	{
		while (counter[6] > count_num(num_int, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_num(num_int, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
}

static void		put_dif_num(int *counter, int num_int)
{
	if (counter[7])
	{
		while (counter[2] > count_num(num_int, counter))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}

void			u_function(int num_int, int *counter)
{
	unsigned int num;

	num = 0;
	if (num_int >= 0)
	{
		zero_32_num_int(num_int, counter);
		if (counter[5] && !counter[6])
		{
			put_dif(counter, num_int);
			return ;
		}
		ft_putnbr_fd(num_int, 1, counter);
		put_dif(counter, num_int);
	}
	else
	{
		num = num_int + 4294967295 + 1;
		zero_32_num(num, counter);
		if (counter[5] && !counter[6])
		{
			put_dif_num(counter, num);
			return ;
		}
		u_putnbr_fd(num, 1, counter);
		put_dif_num(counter, num);
	}
}
