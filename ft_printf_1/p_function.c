/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 00:18:08 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/09 11:38:33 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	p_function(size_t num, int *counter)
{
	if (ft_isdigit(num % 16) && num != 0)
	{
		p_function(num / 16, counter);
		ft_putnbr_fd(num % 16, 1, counter);
	}
	else if (num != 0)
	{
		p_function(num / 16, counter);
		ft_putchar_fd('a' + num % 16 - 10, 1, counter);
	}
}
