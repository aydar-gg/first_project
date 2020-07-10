/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dif_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:03:07 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/09 11:41:03 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_p(size_t num_long)
{
	int i;

	i = 2;
	if (num_long == 0)
		i++;
	while (num_long != 0)
	{
		num_long /= 16;
		i++;
	}
	return (i);
}

void		put_dif_p(size_t num_long, int *counter)
{
	if (counter[7])
	{
		while (counter[2] > count_p(num_long))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}
