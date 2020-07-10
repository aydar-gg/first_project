/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dif_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:40:46 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/07 13:44:31 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_xx(unsigned int num_copy, int *counter)
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

void			put_dif_xx(int *counter, unsigned int num)
{
	if (counter[7])
	{
		while (counter[2] > count_xx(num, counter))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}
