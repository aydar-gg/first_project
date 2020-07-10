/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_0_or_32_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:35:31 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/09 18:48:51 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		put_str(char *str, int *counter)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (counter[5])
			{
				if (counter[6] != 0)
				{
					counter[6]--;
					if (counter[2])
						counter[2]--;
				}
				else
					break ;
			}
			i++;
			counter[3]++;
		}
	}
	write(1, str, i);
}


void			put_0_or_32_s(char *str, int *counter)
{
	if (!str)
		str = "(null)";
	while ((counter[2] > (int)ft_strlen(str) ||
((counter[2] > counter[6]) && counter[5] && counter[6] >= 0)) && !counter[7])
	{
		ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
	if (counter[5] && !counter[6])
	{
		put_dif_s(str, counter);
		counter[0]++;
		return ;
	}
	put_str(str, counter);
	put_dif_s(str, counter);
	counter[0]++;
}
