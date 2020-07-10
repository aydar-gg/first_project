/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:47:56 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/06 18:32:25 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_num(int num_copy, int *counter)
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

void					put_dif(int *counter, int num_int)
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
