/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dif_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:33:31 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/08 16:05:13 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_dif_s(char *str, int *counter)
{
	if (counter[7])
	{
		while (counter[2] > (int)ft_strlen(str) || (counter[2] && counter[5]))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}
