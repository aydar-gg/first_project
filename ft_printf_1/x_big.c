/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_big.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:43:33 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/05 00:17:36 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	x_big(unsigned int num, int *counter)
{
	if (ft_isdigit(num % 16) && num != 0)
	{
		x_big(num / 16, counter);
		ft_putnbr_fd(num % 16, 1, counter);
	}
	else if (num != 0)
	{
		x_big(num / 16, counter);
		ft_putchar_fd('A' + num % 16 - 10, 1, counter);
	}
}
