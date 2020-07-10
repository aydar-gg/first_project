/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_littel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:29:51 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/05 00:17:45 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	x_littel(unsigned int num, int *counter)
{
	if (ft_isdigit(num % 16) && num != 0)
	{
		x_littel(num / 16, counter);
		ft_putnbr_fd(num % 16, 1, counter);
	}
	else if (num != 0)
	{
		x_littel(num / 16, counter);
		ft_putchar_fd('a' + num % 16 - 10, 1, counter);
	}
}
